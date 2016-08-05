
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <stdarg.h>
#include <libgen.h>
#include <sys/stat.h>
#include "aidl_language.h"
#include "BasicType.h"

using namespace std;

/*
typedef struct {
    const char *name;
    const char *constructor;
    const char *decl;
    const char *define;
    const char *declparam;
    const char *writeparam;
    const char *from;
    const char *to;
} TYPEMAP;
*/
static const char *this_proxy_interface;
static const char *this_interface;

static string include_user;
static BasicTypeFactory bt_factory;

static FILE *newfile(const char *filebuff, const string& filename, const char *suffix, const string& originalSrc);

string
gather_comments(extra_text_type* extra, bool tab = true)
{
    string s;
    while (extra) {
        if (extra->which == SHORT_COMMENT) {
            s += extra->data;
        }
        else if (extra->which == LONG_COMMENT) {
            s += "/*";
            s += extra->data;
            s += "*/";
        }
        extra = extra->next;
    }
    if (!s.empty())
    {
        s.append("\n");
    }

    if (s.empty() || !tab)
        return s;

    std::string tmp("    ");
    tmp.append(s);
    return tmp;
}

static type_type make_void_type()
{
    type_type type;
    bzero(&type, sizeof type);
    type.type.data = (char*)"void";
    type.type.extra = NULL;
    return type;
}

static string
escape_backslashes(const string& str)
{
    string result;
    const size_t I=str.length();
    for (size_t i=0; i<I; i++) {
        char c = str[i];
        if (c == '\\') {
            result += "\\\\";
        } else {
            result += c;
        }
    }
    return result;
}

static string makefirstup(const std::string name)
{
    if (name.empty())
    {
        return name;
    }

    std::string tmp(name);
    if (islower(name[0]))
    {
        tmp[0] = toupper(name[0]);
    }

    return tmp;
}

static string makeup(const char *name)
{
    string transactCodeName;
    char ch, lastch = 'A';
    do {
        ch = *name++;
        if (isupper(ch) && islower(lastch))
            transactCodeName = transactCodeName + '_';
        lastch = ch;
        ch = toupper(ch);
        transactCodeName = transactCodeName + ch;
    } while (ch);
    return transactCodeName;
}

static string makelow(const char *name)
{
    string transactCodeName = name;
    for(int i = 0; i < (int)transactCodeName.length(); i++)
        transactCodeName[i] = tolower(transactCodeName[i]);
    return transactCodeName;
}

static void make_method_name(FILE* outputfd,
        char* method_name_data, type_type type, arg_type* method_args, bool oneway,
        char* class_name, const char* arg_pre = NULL)
{
    int i = 0;
    string transactCodeName = makeup(method_name_data);

    fprintf(outputfd, "android::status_t");

    char method_name[100];
    bzero(method_name, sizeof method_name);
    strcpy(method_name, method_name_data);

    if (class_name)
        fprintf(outputfd, " %s::%s(", class_name, method_name);
    else
        fprintf(outputfd, " %s(", method_name);

    arg_type* arg = method_args;

    bool first_arg = true;
    if (arg_pre)
    {
        first_arg = false;
        fprintf(outputfd, "%s", arg_pre);
    }

    while (arg)
    {
        int dir = convert_direction(arg->direction.data);
        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);

        // oneway then just in parameter
        if (oneway && dir != OUT_PARAMETER)
        {
            if (first_arg)
            {
                first_arg = false;
            }
            else
            {
                fprintf(outputfd, ", ");
            }

            //fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
            fprintf(outputfd, bt->declparam().c_str());
        }

        // not oneway then all parameter
        if (!oneway)
        {
            if (first_arg)
            {
                first_arg = false;
            }
            else
            {
                fprintf(outputfd, ", ");
            }

            if (dir == IN_PARAMETER)
                //fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
                fprintf(outputfd, bt->declparam().c_str());
            else
                //fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->writeparam, arg->name.data);
                fprintf(outputfd, bt->writeparam().c_str());
        }

        arg = arg->next;
    }

    fprintf(outputfd, ")");
}

static int method_code_count = 0;
static int command_code_count = 0;
static int notify_code_count = 0;
static int multicast_code_count = 0;

std::vector<std::string> multicast_domain;

static void make_enum_code(FILE* outputfd, interface_item_type* aitem, int filter, std::string domain = std::string())
{
    interface_item_type* item = aitem;
    int enum_count = 0;

    if (filter & 1) 
    {
        fprintf(outputfd, "    enum Method_Code\n    {\n");
        while (item)
        {
            if (item->item_type == METHOD_TYPE) {
                const method_type* method =  (method_type*)item;
                if (!method->oneway)  
                {
                    string method_name= makeup(method->name.data);
                    fprintf(outputfd, "        METHOD_%s", method_name.c_str());
                    if (enum_count == 0) 
                    {
                        fprintf(outputfd, " = SERVICE_FIRST_TRANSACTION,\n");
                    }
                    else
                    {
                        fprintf(outputfd, ",\n");
                    }
                    enum_count ++;
                }
            }
            item = item->next;
        }

        if (enum_count != 0)
            fprintf(outputfd, "\n        METHOD_MAX\n    };\n\n");
        else
            fprintf(outputfd, "\n        METHOD_MAX = SERVICE_FIRST_TRANSACTION\n    };\n\n");

        method_code_count = enum_count;
    }

    if (filter & 2)
    {
        item = aitem;
        fprintf(outputfd, "    enum Command_Code\n    {\n");
        enum_count = 0;
        while (item)
        {
            if (item->item_type == COMMAND_TYPE) {
                const command_type* method =  (command_type*)item;
                if (convert_direction(method->direction.data) == IN_PARAMETER)  
                {
                    string method_name= makeup(method->name.data);
                    fprintf(outputfd, "        COMMAND_%s", method_name.c_str());
                    if (enum_count == 0) 
                    {
                        fprintf(outputfd, " = METHOD_MAX,\n");
                    }
                    else
                    {
                        fprintf(outputfd, ",\n");
                    }
                    enum_count ++;
                }
            }
            item = item->next;
        }

        if (enum_count == 0)
            fprintf(outputfd, "        COMMAND_MAX = METHOD_MAX\n    };\n\n");
        else 
            fprintf(outputfd, "\n        COMMAND_MAX\n    };\n\n");

        command_code_count = enum_count;
    }

    if (filter & 4) 
    {
        item = aitem;
        fprintf(outputfd, "    enum Notify_Code\n    {\n");
        enum_count = 0;
        while (item)
        {
            if (item->item_type == COMMAND_TYPE) {
                const command_type* method =  (command_type*)item;
                if (convert_direction(method->direction.data) == OUT_PARAMETER)  
                {
                    string method_name= makeup(method->name.data);
                    fprintf(outputfd, "        NOTIFY_%s", method_name.c_str());
                    if (enum_count == 0) 
                    {
                        fprintf(outputfd, " = COMMAND_MAX,\n");
                    }
                    else
                    {
                        fprintf(outputfd, ",\n");
                    }
                    enum_count ++;
                }
            }
            item = item->next;
        }

        if (enum_count == 0)
            fprintf(outputfd, "        NOTIFY_MAX = COMMAND_MAX\n    };\n\n");
        else
            fprintf(outputfd, "\n        NOTIFY_MAX\n    };\n\n");

        notify_code_count = enum_count;
    }

    if (filter & 8) 
    {
        item = aitem;
        fprintf(outputfd, "    enum Multicast_Code\n    {\n");
        enum_count = 0;
        while (item)
        {
            if (item->item_type == MULTICAST_TYPE) {
                const multicast_type* method =  (multicast_type*)item;
                string method_name= makeup(method->name.data);
                fprintf(outputfd, "        MULTICAST_%s", method_name.c_str());

                if (enum_count == 0) 
                {
                    fprintf(outputfd, " = SERVICE_FIRST_TRANSACTION,\n");
                }
                else
                {
                    fprintf(outputfd, ",\n");
                }

                if (std::find(multicast_domain.begin(), multicast_domain.end(), method->domain.data) == multicast_domain.end())
                {
                    multicast_domain.push_back(method->domain.data);
                }

                enum_count ++;
            }
            item = item->next;
        }

        fprintf(outputfd, "\n        MULTICAST_MAX\n    };\n\n");

        multicast_code_count = enum_count;
    }
}

static void generate_sub_source_file(FILE* outputfd, interface_item_type* aitem, std::string domain)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    if (domain.compare("multicast"))
        sprintf(class_name, "%sSub%s", this_interface, makefirstup(domain).c_str());
    else
        sprintf(class_name, "%sSub", this_interface);

    fprintf(outputfd, 
    "#include \"sub/%s.h\"\n"\
    "#include \"servicebase/ServiceBase.h\"\n"\
    "namespace goni {\n\n"\
    "%s::%s(I%s *replier, ServiceBase* owner)\n"
    "    : SubBase(owner, \"%s\", \"%s\")\n"\
    "    , m_replier(replier)\n"\
    "{\n}\n\n"\
    "%s::~%s()\n{\n}\n\n",
    class_name, class_name, class_name, class_name, this_interface, domain.c_str(), class_name, class_name);
 

    fprintf(outputfd, "int %s::onMulticast(unsigned int code, const android::Parcel &data)\n{\n    switch(code) {\n", class_name);
    
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;

            if (!domain.compare(method->domain.data)) 
            {
                fprintf(outputfd, "    case MULTICAST_%s:\n    {\n", makeup(method->name.data).c_str());

                arg_type* arg = method->args;
                char arg_str[1000];
                bzero(arg_str, sizeof arg_str);
                while (arg)
                {
                    BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->from(2).c_str());
                    sprintf(arg_str + strlen(arg_str), "%s, ", arg->name.data);

                    arg = arg->next;
                }

                arg_str[strlen(arg_str) - 2] = 0;

                fprintf(outputfd, "        m_replier->%s(%s);\n        break;\n    }\n", method->name.data, arg_str);
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "    }\n\n    return 0;\n}\n}\n/* EOF */");
}

static void generate_sub_header_file(FILE* outputfd, interface_item_type* aitem, std::string domain, bool vf)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    if (domain.compare("multicast"))
        sprintf(class_name, "%sSub%s", this_interface, makefirstup(domain).c_str());
    else
        sprintf(class_name, "%sSub", this_interface);
    
    fprintf(outputfd, "#ifndef __%s_H__\n"\
            "#define __%s_H__\n\n", makeup(class_name).c_str(), makeup(class_name).c_str());
    
    fprintf(outputfd, "#include <string>\n");
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n");
    fprintf(outputfd, "#include \"SubBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseDefines.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "#include \"%sServiceDefines.h\"\n", this_interface);
    fprintf(outputfd, "%s", include_user.c_str());

    fprintf(outputfd, "namespace goni {\nclass ServiceBase;\n\n");
    fprintf(outputfd, "class I%s\n{\npublic:\n    virtual ~I%s() {}\n\n", class_name, class_name);
    
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE)
        {
            multicast_type* method =  (multicast_type*)item;
            if (!domain.compare(method->domain.data))
            {
                fprintf(outputfd, "%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "    virtual ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
                if (vf) 
                {
                    fprintf(outputfd, " { return 0; }\n");
                }
                else 
                {
                    fprintf(outputfd, " = 0;\n");
                }
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "\n};\n\n");

    fprintf(outputfd, "class %s : public SubBase\n{\npublic:\n", class_name);

    make_enum_code(outputfd, aitem, 8);

    fprintf(outputfd, "public:\n    %s(I%s* replier, ServiceBase* owner);\n    ~%s();\n\n", class_name, class_name, class_name);
    fprintf(outputfd, "    virtual int onMulticast(unsigned int code, const android::Parcel &data);\n\n");

    fprintf(outputfd, "private:\n    I%s* m_replier;\n    SenderId m_id;\n\n};\n}\n#endif\n/*EOF*/", class_name);
}

static void generate_enum_define(std::string include_str, document_item_type* aitem, const std::string& orc)
{
    char tmp_file_name[1024];
    bzero(tmp_file_name, sizeof(tmp_file_name));
    sprintf(tmp_file_name, "%sServiceDefines", this_interface);
    std::string file_name = std::string(tmp_file_name, strlen(tmp_file_name));
    FILE* outputfd = newfile(include_str.c_str(), file_name, ".h", orc);

    fprintf(outputfd, "#ifndef __%s_SERVICE_DEFINES_H__\n", this_interface);
    fprintf(outputfd, "#define __%s_SERVICE_DEFINES_H__\n", this_interface);
    fprintf(outputfd, "namespace goni {\n\n");
    while (aitem)
    {
        if (aitem->item_type == ENUM_DATA_TYPE)
        {
            enum_data_type* method = (enum_data_type*)aitem;
            fprintf(outputfd, "%s", gather_comments(method->comments_token->extra, false).c_str());
            fprintf(outputfd, "enum %s \n{\n", method->name.data);
            enum_list* el = method->enumm_list;
            while (el)
            {
                fprintf(outputfd, "%s", gather_comments(el->item->comma_token->extra).c_str());
                fprintf(outputfd, "    %s", el->item->name.data);
                if (el->item->has_value) 
                    fprintf(outputfd, "= %s,\n", el->item->value.data);
                else
                    fprintf(outputfd, ",\n");

                el = el->next;
            }
            fprintf(outputfd, "};\n\n");
        }

        aitem = aitem->next;
    }

    fprintf(outputfd, "\n}/*namespace goni*/\n#endif\n/* EOF */");

    fclose(outputfd);
}

static void generate_replier_source_file(FILE* outputfd, interface_item_type* aitem, bool replierBase)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    if(replierBase)
    {
        sprintf(class_name, "%sReplierBase", this_interface);
    }
    else
    {
        sprintf(class_name, "%sReplier", this_interface);
    }

    
    fprintf(outputfd, "#include \"%s.h\"\n", class_name);
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBase.h\"\n");
    fprintf(outputfd, "#include \"%sStubBase.h\"\n\n", this_interface);
    fprintf(outputfd, "namespace goni {\n\n");

    fprintf(outputfd, "%s::%s(ServiceBase* owner)\n    :m_owner(owner)\n{\n}\n", class_name, class_name);
    fprintf(outputfd, "%s::~%s() {}\n\n", class_name, class_name);

    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, class_name, "SenderId id");
                fprintf(outputfd, "\n{\n");
                fprintf(outputfd, "    android::Parcel _data;\n");
                // fprintf(outputfd, "    _data.writeInt32(id);\n");
                
                arg_type* arg = method->args;
                while (arg)
                {
                    //TYPEMAP* tm = lookup_type(arg->type.type.data);
                    BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->to(1).c_str());
                    arg = arg->next;
                }

                fprintf(outputfd, "\n");
                fprintf(outputfd, "    m_owner->sendAsyncResponse(id, %sStubBase::NOTIFY_%s, _data);\n    return 0;\n}\n", this_interface, makeup(method->name.data).c_str());
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "}\n/* EOF */");

}

static void generate_replier_header_file(FILE* outputfd, interface_item_type* aitem, bool replierBase)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    if(replierBase)
    {
        sprintf(class_name, "%sReplierBase", this_interface);
    }
    else
    {
        sprintf(class_name, "%sReplier", this_interface);
    }

    
    fprintf(outputfd, "#ifndef __%s_H__\n"\
            "#define __%s_H__\n\n", makeup(class_name).c_str(), makeup(class_name).c_str());
    
    fprintf(outputfd, "#include \"StubBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "#include \"%sServiceDefines.h\"\n", this_interface);
    fprintf(outputfd, "%s", include_user.c_str());

    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "class ServiceBase;\n\n");
    fprintf(outputfd, "class %s\n{\npublic:\n    %s(ServiceBase* owner);\n    ~%s();\n\n", class_name, class_name, class_name);

    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                fprintf(outputfd, "%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "    ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL, "SenderId id");
                fprintf(outputfd, ";\n");
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "\nprivate:\n    ServiceBase* m_owner;\n};\n}\n#endif\n/* EOF */");
}


static void generate_stub_source_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sStubBase", this_interface);

    fprintf(outputfd, "#include \"%s.h\"\n", class_name);
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBase.h\"\n\n");
    fprintf(outputfd, "namespace goni {\n\n");

    fprintf(outputfd, "%s::%s(ServiceBase* owner)\n    : StubBase(owner)\n{\n", class_name, class_name);
    std::vector<std::string>::iterator it = multicast_domain.begin();
    for (; it != multicast_domain.end(); it++)
        fprintf(outputfd, "    m_owner->createPublisher(\"%s\");\n", it->c_str());

    fprintf(outputfd, "}\n\n");

    fprintf(outputfd, "%s::~%s()\n{\n", class_name, class_name);
    it = multicast_domain.begin();
    for (; it != multicast_domain.end(); it++)
        fprintf(outputfd, "    m_owner->destroyPublisher(\"%s\");\n", it->c_str());
    fprintf(outputfd, "}\n\n");


    fprintf(outputfd, "int %s::onSyncRequest(unsigned int code, const android::Parcel &data, android::Parcel& _data)\n{\n", class_name);
    fprintf(outputfd, "    switch (code) {\n");

    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            if (!method->oneway)
            {
                fprintf(outputfd, "    case METHOD_%s:\n    {\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                char arg_buf[100];
                bzero(arg_buf, sizeof(arg_buf));
                while (arg)
                {
                    BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER)
                    {
                        fprintf(outputfd, bt->from(2).c_str());
                    }
                    else
                    {
                        //TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "        ");
                        fprintf(outputfd, bt->declare().c_str());
                    }

                    sprintf(arg_buf + strlen(arg_buf), "%s, ", arg->name.data);

                    arg = arg->next;
                }

                if (strlen(arg_buf) != 0)
                {
                    arg_buf[strlen(arg_buf) - 2 ] = 0;
                }

                fprintf(outputfd, "        %s(%s);\n\n", method->name.data, arg_buf);

                arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        //TYPEMAP* tm = lookup_type(arg->type.type.data);
                        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->to(2).c_str());
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "        break;\n    }\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "    }\n\n    return 0;\n}\n");

    fprintf(outputfd, "int %s::onAsyncRequest(SenderId &id, unsigned int code, const android::Parcel &data)\n{\n", class_name);
    fprintf(outputfd, "    switch (code) {\n");

    item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "    case COMMAND_%s:\n    {\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                char arg_buf[100];
                bzero(arg_buf, sizeof(arg_buf));
                sprintf(arg_buf, "id, ");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->from(2).c_str());
                        sprintf(arg_buf + strlen(arg_buf), "%s, ", arg->name.data);

                    }
                    arg = arg->next;
                }

                if (strlen(arg_buf) != 0)
                {
                    arg_buf[strlen(arg_buf) - 2] = 0;
                }

                fprintf(outputfd, "        %s(%s);\n\n", method->name.data, arg_buf);

                fprintf(outputfd, "        break;\n    }\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "    }\n\n    return 0;\n}\n");

    item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) {
            multicast_type* method =  (multicast_type*)item;

            make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, class_name);
            fprintf(outputfd, "\n{\n    android::Parcel _data;\n");
            fprintf(outputfd, "    _data.writeCString(\"%s\");\n", this_interface);
            fprintf(outputfd, "    _data.writeCString(\"%s\");\n", method->domain.data);
            arg_type* arg = method->args;
            while (arg)
            {
                //TYPEMAP* tm = lookup_type(arg->type.type.data);
                BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                fprintf(outputfd, bt->to(1).c_str());

                arg = arg->next;
            }

            fprintf(outputfd, "\n    return m_owner->sendMulticast(\"%s\", MULTICAST_%s, _data);\n}\n",method->domain.data, makeup(method->name.data).c_str());

        }

        item = item->next;
    }

    fprintf(outputfd, "}\n/* EOF */");
}

static void generate_stub_header_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sStubBase", this_interface);

    fprintf(outputfd, "#ifndef __%s_H__\n"\
            "#define __%s_H__\n\n"\
            "#include <string>\n"\
            "#include \"StubBase.h\"\n" \
            "#include \"binder/Parcel.h\"\n" \
            "#include \"servicebase/ServiceBaseDefines.h\"\n\n" \
            "#include \"servicebase/ServiceBaseGlobal.h\"\n\n" \
            , makeup(class_name).c_str(), makeup(class_name).c_str());

    fprintf(outputfd, "#include \"%sServiceDefines.h\"\n", this_interface);
    fprintf(outputfd, "%s", include_user.c_str());
            

    fprintf(outputfd, "namespace goni {\nclass ServiceBase;\n\n");

    fprintf(outputfd, "class %s : public StubBase\n{\npublic:\n", class_name);
    fprintf(outputfd, "    %s(ServiceBase* owner);\n    virtual ~%s();\n\n", class_name, class_name);

    make_enum_code(outputfd, aitem, 0xf);

    fprintf(outputfd, "private:\n\
    virtual int onSyncRequest(unsigned int code, const android::Parcel &data, android::Parcel& reply);\n\
    virtual int onAsyncRequest(SenderId &id, unsigned int code, const android::Parcel &data);\n\n");

    fprintf(outputfd, "protected:\n");
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            fprintf(outputfd, "    virtual ");
            make_method_name(outputfd, method->name.data, method->type, method->args, method->oneway, NULL);
            fprintf(outputfd, " = 0;\n");
        }
        else if (item->item_type == COMMAND_TYPE)
        {
            command_type* method = (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "    virtual ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL, "SenderId id");
                fprintf(outputfd, " = 0;\n");
            }
        }
        item = item->next;
    }
    fprintf(outputfd, "\npublic:\n");
    item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;
            fprintf(outputfd, "    ");
            make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
            fprintf(outputfd, ";\n");
        }
        item = item->next;
    }

    fprintf(outputfd, "};\n}\n#endif\n/* EOF */");
}

static void generate_proxy_source_file(FILE *outputfd, interface_item_type* aitem)
{
    int i = 0;
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sProxyBase", this_interface);

    fprintf(outputfd, "#include \"proxy/%s.h\"\n", class_name);
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n\n");
    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "%s::%s(%sProxyReplier* replier)\n    :ServiceProxyBase(\"%s\")\n    ,m_replier(replier)\n{\n",
            class_name, class_name, this_proxy_interface, this_interface);
    if (notify_code_count > 0) 
    {
        fprintf(outputfd, "    setupAsyncRequest();\n}\n");
        fprintf(outputfd, "%s::~%s()\n{\n    teardownAsyncRequest();\n}\n", class_name, class_name);
    }
    else 
    {
        fprintf(outputfd, "}\n");
        fprintf(outputfd, "%s::~%s()\n{\n}\n", class_name, class_name);
    }

    
    fprintf(outputfd, "void %s::onConnected()\n{\n    ServiceProxyBase::onConnected();\n    m_replier->onConnected();\n}\n", class_name);
    fprintf(outputfd, "void %s::onDisconnected()\n{\n    ServiceProxyBase::onDisconnected();\n    m_replier->onDisconnected();\n}\n\n", class_name);
    
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            make_method_name(outputfd, method->name.data, method->type, method->args, method->oneway, class_name);
            fprintf(outputfd, "\n{\n");
                
            arg_type* arg;
            if (!method->oneway)
            {
                arg = method->args;
                fprintf(outputfd, "    android::Parcel data, _data;\n");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->to(1).c_str());;
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "    int ret = sendSyncRequest(METHOD_%s, _data, &data);\n", makeup(method->name.data).c_str());
                fprintf(outputfd, "    if (ret == BS_NO_ERROR) {\n");
                arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER) 
                    {
                        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->from(2, false).c_str());;
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, "    }\n");
                fprintf(outputfd, "    return ret;\n}\n");
            }
        }
        else if (item->item_type == COMMAND_TYPE)
        {
            command_type* method = (command_type*) item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, class_name);
                fprintf(outputfd, "\n{\n");
                arg_type* arg = method->args;
                fprintf(outputfd, "    android::Parcel _data;\n");
                fprintf(outputfd, "    prepareAsyncData(_data);\n");
                while (arg)
                {
                    BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->to(1).c_str());;
                    arg = arg->next;
                }
                fprintf(outputfd, "    return sendAsyncRequest(COMMAND_%s, _data);\n}\n", makeup(method->name.data).c_str());
            }
        }

        item = item->next;
    }

    // async response
    fprintf(outputfd, "int %s::onAsyncResponse(unsigned int code, const android::Parcel &data)\n{\n    switch(code) {\n", class_name);
    item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                fprintf(outputfd, "    case NOTIFY_%s:\n    {\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                char arg_buf[100];
                bzero(arg_buf, sizeof(arg_buf));
                while (arg)
                {
                    BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->from(2).c_str());;
                    sprintf(arg_buf + strlen(arg_buf), "%s, ", arg->name.data);
                    arg = arg->next;
                }

                if (strlen(arg_buf) != 0)
                {
                    arg_buf[strlen(arg_buf) - 2 ] = 0;
                }

                fprintf(outputfd, "        m_replier->%s(%s);", method->name.data, arg_buf);
                fprintf(outputfd, "\n        break;\n    }\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "    }\n    return 0;\n}\n");

    fprintf(outputfd, "}\n/* EOF */");
}

static void generate_proxy_header_file(FILE *outputfd, interface_item_type* aitem, bool vf)
{
    int i;
    interface_item_type* item = aitem;

    fprintf(outputfd, "#ifndef GONI_%s_PROXY_BASE_H\n#define GONI_%s_PROXY_BASE_H\n\n", makeup(this_interface).c_str(), makeup(this_interface).c_str());
    //fprintf(outputfd, "#include <utils/Errors.h>\n");
    fprintf(outputfd, "#include\"servicebase/ServiceProxyBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseDefines.h\"\n\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "#include \"%sServiceDefines.h\"\n", this_interface);
    fprintf(outputfd, "%s", include_user.c_str());

    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "class %sProxyReplier\n{\npublic:\n", this_proxy_interface);
    fprintf(outputfd, "    virtual ~%sProxyReplier() {}\n\n", this_proxy_interface);
    fprintf(outputfd, "    virtual void onConnected() {}\n\n");
    fprintf(outputfd, "    virtual void onDisconnected() {}\n\n");

    while (item) 
    {
        if (item->item_type == COMMAND_TYPE) {
            const command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                fprintf(outputfd, "%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "    virtual ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
                if (vf) 
                {
                    fprintf(outputfd, " { return 0; }\n");
                }
                else 
                {
                    fprintf(outputfd, " = 0;\n");
                }
            }
        }

        item = item->next;
    }
    fprintf(outputfd, "};\n\n");
    
    fprintf(outputfd, "class %sProxyBase : public ServiceProxyBase\n{\npublic:\n", this_interface);
    make_enum_code(outputfd, aitem, 7);

    fprintf(outputfd, "public:\n");
    fprintf(outputfd, "    %sProxyBase(%sProxyReplier* replier);\n", this_interface, this_proxy_interface);
    fprintf(outputfd, "    ~%sProxyBase();\n\n", this_interface);
    fprintf(outputfd, "    virtual void onConnected();\n");
    fprintf(outputfd, "    virtual void onDisconnected();\n\n");

    item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            fprintf(outputfd, "%s", gather_comments(method->comments_token->extra).c_str());
            fprintf(outputfd, "    ");
            make_method_name(outputfd, method->name.data, method->type, method->args, method->oneway, NULL);
            fprintf(outputfd, ";\n");
        }
        else if (item->item_type == COMMAND_TYPE) {
            const command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "    ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
                fprintf(outputfd, ";\n");
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "private:\n" \
                      "    virtual int onAsyncResponse(unsigned int code, const android::Parcel &reply);\n\n"\
                      "private:\n"\
                      "    %sProxyReplier* m_replier;\n", this_proxy_interface);
    
    fprintf(outputfd, "};\n}\n");

    fprintf(outputfd, "#endif\n/* EOF */");
}

static void generate_user_data(user_data_type* p, const string& inc_str)
{
    string filename;
    filename.append(inc_str);

    filename.append(p->name.data);
    filename.append(".h");

    include_user.append("#include \"");
    include_user.append(p->name.data);
    include_user.append(".h\"\n");

    printf("imports filename is %s\n", filename.c_str());

    if (access(filename.c_str(), F_OK) == 0) {
        unlink(filename.c_str());
    }

    FILE* outputfd = fopen(filename.c_str(), "wb");

    if (outputfd == NULL) {
        return ;
    }

    arg_type* arg = p->args;

    char *write_buf = (char*)malloc(102400);
    char *read_buf = (char*)malloc(102400);
    char *init_buf = (char*)malloc(10240);
    char *inc_buf = (char*)malloc(10240);

    bzero(write_buf, 102400);
    bzero(read_buf, 102400);
    bzero(init_buf, 10240);
    bzero(inc_buf, 10240);


    while (arg) {
        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
        sprintf(read_buf + strlen(read_buf), bt->from(2, false).c_str());
        sprintf(write_buf + strlen(write_buf), bt->to(2).c_str());

        sprintf(init_buf + strlen(init_buf), "\n        %s,", bt->constructor().c_str());
        if (!bt->basicType()) {
            sprintf(inc_buf + strlen(inc_buf), "#include\"%s.h\"\n", arg->type.type.data);
        }

        arg = arg->next;
    }

    // start write
    fprintf(outputfd, "#ifndef __%s_H__\n", makeup(p->name.data).c_str());
    fprintf(outputfd, "#define __%s_H__\n\n", makeup(p->name.data).c_str());
    fprintf(outputfd, "#include <vector>\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "#include \"%sServiceDefines.h\"\n", this_interface);
    fprintf(outputfd, "%s\n", inc_buf);
    fprintf(outputfd, "namespace goni {\n");
    fprintf(outputfd, "class %s : public android::RefBase\n{\n", p->name.data);
    fprintf(outputfd, "public:\n");

    if (strlen(init_buf) != 0) {
        init_buf[strlen(init_buf) - 1] = 0;
        fprintf(outputfd, "\n    %s():%s\n    {\n    }\n",p->name.data, init_buf);
    }


    arg = p->args;
    while (arg) {
        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
        fprintf(outputfd, "%s", bt->getFunc(1).c_str());
        arg = arg->next;
    }

    fprintf(outputfd, "    void readFromParcel(const android::Parcel& data)\n    {\n");
    fprintf(outputfd, "%s    }\n", read_buf);

    fprintf(outputfd, "    void writeToParcel(android::Parcel& _data)\n    {\n");
    fprintf(outputfd, "%s    }\n", write_buf);

    fprintf(outputfd, "private:\n");

    arg = p->args;
    while (arg)
    {
        BasicType* bt = bt_factory.create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
        fprintf(outputfd, "%s", gather_comments(arg->type.type.extra).c_str());
        fprintf(outputfd, "    %s\n", bt->define().c_str());
        arg = arg->next;
    }

    fprintf(outputfd, "\n};\n");
    fprintf(outputfd, "typedef android::sp<%s> %s_Sp;\n", p->name.data, p->name.data);
    fprintf(outputfd, "typedef std::vector<android::sp<%s> > %s_SpVec;\n", p->name.data, p->name.data);
    fprintf(outputfd,"\n}\n#endif");

    fclose(outputfd);
}

static FILE *newfile(const char *filebuff, const string& filename, const char *suffix, const string& originalSrc)
{
    char tmp_buf[1024];
    bzero(tmp_buf, sizeof(tmp_buf));
    strcpy(tmp_buf, filebuff);
    strcat(tmp_buf, filename.c_str());
    strcat(tmp_buf, suffix);
    //printf("outputting... filename=%s\n", filebuff);
    if (access(tmp_buf, F_OK) == 0) {
        unlink(tmp_buf);
    }
    FILE* outputfd = fopen(tmp_buf, "wb");
    if (!outputfd) {
        fprintf(stderr, "unable to open %s for write\n", tmp_buf);
        exit(1);
    }
    fprintf(outputfd, "/*\n * This file is auto-generated.  DO NOT MODIFY.\n"
            " * Original file: %s\n */\n", escape_backslashes(originalSrc).c_str());
    return outputfd;
}

void init_user_data(document_item_type* docus)
{
    while (docus) {
        if (docus->item_type == USER_DATA_TYPE) {
            user_data_type* item = (user_data_type*)docus;
            bt_factory.set_user_data(item->name.data, BasicTypeFactory::USER_DATA);
        }
        else if (docus->item_type == ENUM_DATA_TYPE) {
            enum_data_type* item = (enum_data_type*)docus;
            bt_factory.set_user_data(item->name.data, BasicTypeFactory::ENUM_DATA);
        }

        docus = docus->next;
    }

}

void init_interface_name(document_item_type* docus)
{
    while (docus)
    {
        if (docus->item_type == INTERFACE_TYPE_BINDER) {
            interface_type* iface = (interface_type*)docus;
            this_proxy_interface = iface->name.data;
            this_interface = &this_proxy_interface[1];
        }

        docus = docus->next;
    }
}

// =================================================
int
generate_cpp(const string& filename, const string& originalSrc, document_item_type* docus, bool virtualFunc, bool replierBase)
{
    if (filename == "-") {
        printf("[%s:%d] stdout not supported!!\n", __FUNCTION__, __LINE__);
        exit(1);
    }

    char tmp_file_name[100];

    string include_str = filename + "/include/";

    if (access(include_str.c_str(), F_OK) != 0) {
        mkdir(include_str.c_str(), 0777);
    }

    string src_str = filename + "/src/";
    if (access(src_str.c_str(), F_OK) != 0) {
        mkdir(src_str.c_str(), 0777);
    }

    string proxy_inc_str = include_str + "/proxy/";
    string stub_inc_str = src_str + "/stub/";
    
    string proxy_src_str = src_str + "/proxy/";
    string stub_src_str = src_str + "/stub/";

    if (access(proxy_inc_str.c_str(), F_OK) != 0) {
        mkdir(proxy_inc_str.c_str(), 0777);
    }
    
    if (access(proxy_src_str.c_str(), F_OK) != 0) {
        mkdir(proxy_src_str.c_str(), 0777);
    }
    
    if (access(stub_inc_str.c_str(), F_OK) != 0) {
        mkdir(stub_inc_str.c_str(), 0777);
    }
    
    if (access(stub_src_str.c_str(), F_OK) != 0) {
        mkdir(stub_src_str.c_str(), 0777);
    }

    init_user_data(docus);

    init_interface_name(docus);

    document_item_type* docus_bak = docus;

    while (docus) {
        if (docus->item_type == USER_DATA_TYPE) {
            generate_user_data((user_data_type*)docus, include_str);
        }
        else if (docus->item_type == INTERFACE_TYPE_BINDER) {
            interface_type* iface = (interface_type*)docus;
            this_proxy_interface = iface->name.data;
            this_interface = &this_proxy_interface[1];

            bzero(tmp_file_name, sizeof(tmp_file_name));
            sprintf(tmp_file_name, "%sProxyBase", this_interface);
            std::string file_name(tmp_file_name, strlen(tmp_file_name));

            FILE* outputfd = newfile(proxy_inc_str.c_str(), file_name, ".h", originalSrc);
            generate_proxy_header_file(outputfd, iface->interface_items, virtualFunc);
            fclose(outputfd);

            outputfd = newfile(proxy_src_str.c_str(), file_name, ".cpp", originalSrc);
            generate_proxy_source_file(outputfd, iface->interface_items);
            fclose(outputfd);

            bzero(tmp_file_name, sizeof(tmp_file_name));
            sprintf(tmp_file_name, "%sStubBase", this_interface);
            file_name = std::string(tmp_file_name, strlen(tmp_file_name));

            outputfd = newfile(stub_inc_str.c_str(), file_name, ".h", originalSrc);
            generate_stub_header_file(outputfd, iface->interface_items);
            fclose(outputfd);

            outputfd = newfile(stub_src_str.c_str(), file_name, ".cpp", originalSrc);
            generate_stub_source_file(outputfd, iface->interface_items);
            fclose(outputfd);

            bzero(tmp_file_name, sizeof(tmp_file_name));
            if(replierBase)
            {
                sprintf(tmp_file_name, "%sReplierBase", this_interface);
            }
            else
            {
                sprintf(tmp_file_name, "%sReplier", this_interface);
            }

            file_name = std::string(tmp_file_name, strlen(tmp_file_name));

            outputfd = newfile(stub_inc_str.c_str(), file_name, ".h", originalSrc);
            generate_replier_header_file(outputfd, iface->interface_items, replierBase);
            fclose(outputfd);

            outputfd = newfile(stub_src_str.c_str(), file_name, ".cpp", originalSrc);
            generate_replier_source_file(outputfd, iface->interface_items, replierBase);
            fclose(outputfd);

            if (multicast_code_count > 0)
            {
                string sub_inc_str = include_str + "/sub/";
                if (access(sub_inc_str.c_str(), F_OK) != 0) {
                    mkdir(sub_inc_str.c_str(), 0777);
                }
                
                string sub_src_str = src_str + "/sub/";
                if (access(sub_src_str.c_str(), F_OK) != 0) {
                    mkdir(sub_src_str.c_str(), 0777);
                }

                std::vector<std::string>::iterator it = multicast_domain.begin();
                for (; it != multicast_domain.end(); it++)
                {
                    bzero(tmp_file_name, sizeof(tmp_file_name));
                    if (it->compare("multicast"))
                        sprintf(tmp_file_name, "%sSub%s", this_interface, makefirstup(*it).c_str());
                    else
                        sprintf(tmp_file_name, "%sSub", this_interface);
                    file_name = std::string(tmp_file_name, strlen(tmp_file_name));

                    outputfd = newfile(sub_inc_str.c_str(), file_name, ".h", originalSrc);
                    generate_sub_header_file(outputfd, iface->interface_items, *it, virtualFunc);
                    fclose(outputfd);

                    outputfd = newfile(sub_src_str.c_str(), file_name, ".cpp", originalSrc);
                    generate_sub_source_file(outputfd, iface->interface_items, *it);
                    fclose(outputfd);
                }
            }


        }

        docus = docus->next;
    }

    docus = docus_bak;
    
    generate_enum_define(include_str, docus_bak, originalSrc);

    return 0;
}
