
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

string
gather_comments(extra_text_type* extra)
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
    return s;
}

static type_type make_void_type()
{
    type_type type;
    bzero(&type, sizeof type);
    type.type.data = (char*)"void";
    type.type.extra = NULL;
    return type;
}

/*
bool check_basic_type(const char* name)
{
    const char* bt[] = {"int", "int64", "byte", "boolean", "String", "String8", "CString", "CharSequence", "float"};
    for (int i = 0; i < sizeof(bt)/sizeof(bt[0]); i++) {
        if (strcmp(name, bt[i]) == 0) {
            return true;
        }
    }

    return false;
}

static TYPEMAP* lookup_type(const char *name)
{
    static TYPEMAP typemap[] = {
        {
            "int",
            "()"
            "int %s = 0;\n",
            "int %s;\n",
            "int",
            "int&",
            "%s = data.readInt32();\n",
            "_data.writeInt32(%s);\n"
        },
        {
            "int64",
            "()",
            "int64_t %s = 0;\n",
            "int64_t %s;\n",
            "int64_t",
            "int64_t&",
            "%s = data.readInt64();\n",
            "_data.writeInt64(%s);\n"
        },
        {
            "byte",
            "()",
            "char %s = 0;\n",
            "char %s;\n",
            "char",
            "char&",
            "%s = data.readByte();\n",
            "_data.writeByte(%s);\n"
        },
        {
            "bool",
            "()",
            "bool %s = false;\n",
            "bool %s;\n",
            "bool",
            "bool&",
            "%s = %data.readInt32();\n",
            "_data.writeInt32((int)%s);\n"
        },
        {
            "String16",
            "()",
            "android::String16 %s;\n",
            "android::String16 %s;\n",
            "const android::String16&",
            "android::String16&",
            "%s = data.readString16();\n",
            "_data.writeString16(%s);\n"
        },
        {
            "String8",
            "()",
            "android::String8 %s;\n",
            "android::String8 %s;\n",
            "const android::String8&",
            "android::String8&",
            "%s = data.readString8();\n",
            "_data.writeString8(%s);\n"
        },
        {
            "string",
            "std::string %s;\n",
            "std::string %s;\n",
            "const std::string&",
            "std::string&",
            "%s = data.readstring();\n",
            "_data.writestring(%s);\n"
        },
        {
            "float",
            "float %s = 0.0;\n",
            "float %s = 0.0;\n",
            "float", "float&",
            "%s = data.readFloat();\n",
            "_data.writeFloat(%s);\n"
        },
        {0, 0, 0, 0, 0, 0}};

    static TYPEMAP pattern =
    {
        "%s",
        "android::sp<%s> %%s(new %s);\n",
        "android::sp<%s> %%s;\n",
        "const android::sp<%s>&",
        "android::sp<%s>&",
        "%%s->readFromParcel(data);\n",
        "%%s->writeToParcel(_data);\n"
    };
    static char temps[7][100];
    static TYPEMAP temp = {(const char *)temps[0], (const char *)temps[1], (const char *)temps[2],
                           (const char *)temps[3], (const char *)temps[4], (const char*)temps[5]
                          ,(const char*)temps[6]};

    TYPEMAP *p = typemap;
    while (p->name && strcmp(name, p->name))
        p++;
    if (!p->name) {
        sprintf(temps[0], pattern.name, name);
        sprintf(temps[1], pattern.decl, name, name);
        sprintf(temps[2], pattern.define, name);
        sprintf(temps[3], pattern.declparam, name);
        sprintf(temps[4], pattern.writeparam, name);
        sprintf(temps[5], pattern.from);
        sprintf(temps[6], pattern.to);
        return &temp;
#if 0
        printf ("lookup_type: failed to find '%s'\n", name);
        exit(1);
        return NULL;
#endif
    }

    return p;
}
*/
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
        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);

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
                fprintf(outputfd, " ,");
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

static void make_enum_code(FILE* outputfd, interface_item_type* aitem, int filter = 0Xf)
{
    interface_item_type* item = aitem;
    int enum_count = 0;

    if (filter & 1) 
    {
        fprintf(outputfd, "\tenum Method_Code\n\t{\n");
        while (item)
        {
            if (item->item_type == METHOD_TYPE) {
                const method_type* method =  (method_type*)item;
                if (!method->oneway)  
                {
                    string method_name= makeup(method->name.data);
                    fprintf(outputfd, "\t\tMETHOD_%s", method_name.c_str());
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
            fprintf(outputfd, "\n\t\tMETHOD_MAX\n\t};\n\n");
        else
            fprintf(outputfd, "\n\t\tMETHOD_MAX = SERVICE_FIRST_TRANSACTION\n\t};\n\n");

        method_code_count = enum_count;
    }

    if (filter & 2)
    {
        item = aitem;
        fprintf(outputfd, "\tenum Command_Code\n\t{\n");
        enum_count = 0;
        while (item)
        {
            if (item->item_type == COMMAND_TYPE) {
                const command_type* method =  (command_type*)item;
                if (convert_direction(method->direction.data) == IN_PARAMETER)  
                {
                    string method_name= makeup(method->name.data);
                    fprintf(outputfd, "\t\tCOMMAND_%s", method_name.c_str());
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
            fprintf(outputfd, "\t\tCOMMAND_MAX = METHOD_MAX\n\t};\n\n");
        else 
            fprintf(outputfd, "\n\t\tCOMMAND_MAX\n\t};\n\n");

        command_code_count = enum_count;
    }

    if (filter & 4) 
    {
        item = aitem;
        fprintf(outputfd, "\tenum Notify_Code\n\t{\n");
        enum_count = 0;
        while (item)
        {
            if (item->item_type == COMMAND_TYPE) {
                const command_type* method =  (command_type*)item;
                if (convert_direction(method->direction.data) == OUT_PARAMETER)  
                {
                    string method_name= makeup(method->name.data);
                    fprintf(outputfd, "\t\tNOTIFY_%s", method_name.c_str());
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
            fprintf(outputfd, "\t\tNOTIFY_MAX = COMMAND_MAX\n\t};\n\n");
        else
            fprintf(outputfd, "\n\t\tNOTIFY_MAX\n\t};\n\n");

        notify_code_count = enum_count;
    }

    if (filter & 8) 
    {
        item = aitem;
        fprintf(outputfd, "\tenum Multicast_Code\n\t{\n");
        enum_count = 0;
        while (item)
        {
            if (item->item_type == MULTICAST_TYPE) {
                const multicast_type* method =  (multicast_type*)item;
                string method_name= makeup(method->name.data);
                fprintf(outputfd, "\t\tMULTICAST_%s", method_name.c_str());
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
            item = item->next;
        }

        fprintf(outputfd, "\n\t\tMULTICAST_MAX\n\t};\n\n");

        multicast_code_count = enum_count;
    }
}

static void generate_sub_source_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sSub", this_interface);

    fprintf(outputfd, 
    "#include \"%s.h\"\n"\
    "#include \"servicebase/ServiceBase.h\"\n"\
    "namespace goni {\n\n"\
    "%s::%s(I%s *replier, ServiceBase* owner)\n"
    "\t: SubBase(\"%s\", \"%s\")\n "\
    "\t, m_replier(replier)\n"\
    "\t, m_owner(owner)\n"\
    "\t, m_name(\"%s\")\n{\n"\
    "\tm_owner->addSubscriber(this);\n}\n\n"\
    "%s::~%s()\n{\n"\
    "\tm_owner->removeSubscriber(this);\n}\n\n",
    class_name, class_name, class_name, class_name, this_interface, this_interface, this_interface, class_name, class_name);
 

    fprintf(outputfd, "int %s::onMulticast(unsigned int code, const android::Parcel &data)\n{\n\tswitch(code) {\n", class_name);
    
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;
            fprintf(outputfd, "\tcase MULTICAST_%s:\n\t{\n", makeup(method->name.data).c_str());

            arg_type* arg = method->args;
            char arg_str[1000];
            bzero(arg_str, sizeof arg_str);
            while (arg)
            {
                BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                fprintf(outputfd, bt->from(2).c_str());
                sprintf(arg_str + strlen(arg_str), "%s, ", arg->name.data);

                arg = arg->next;
            }

            arg_str[strlen(arg_str) - 2] = 0;

            fprintf(outputfd, "\t\tm_replier->%s(%s);\n\t\tbreak;\n\t}\n", method->name.data, arg_str);
        }
        item = item->next;
    }

    fprintf(outputfd, "\t}\n\n\treturn 0;\n}\n}\n/* EOF */");
}

static void generate_sub_header_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sSub", this_interface);
    
    fprintf(outputfd, "#ifndef __%s_H__\n"\
            "#define __%s_H__\n\n", makeup(class_name).c_str(), makeup(class_name).c_str());
    
    fprintf(outputfd, "#include <string>\n");
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n");
    fprintf(outputfd, "#include \"SubBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseDefines.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "%s", include_user.c_str());

    fprintf(outputfd, "namespace goni {\nclass ServiceBase;\n\n");
    fprintf(outputfd, "class I%s\n{\npublic:\n\tvirtual ~I%s() {}\n\n", class_name, class_name);
    
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;
            fprintf(outputfd, "\t%s", gather_comments(method->comments_token->extra).c_str());
            fprintf(outputfd, "\tvirtual ");
            make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
            fprintf(outputfd, " = 0;\n");
        }
        item = item->next;
    }

    fprintf(outputfd, "\n};\n\n");

    fprintf(outputfd, "class %s : public SubBase\n{\npublic:\n", class_name);

    make_enum_code(outputfd, aitem, 8);

    fprintf(outputfd, "public:\n\t%s(I%s* replier, ServiceBase* owner);\n\t~%s();\n\n", class_name, class_name, class_name);
    fprintf(outputfd, "\tvirtual int onMulticast(unsigned int code, const android::Parcel &data);\n\n");

    fprintf(outputfd, "private:\n\tI%s* m_replier;\n\tServiceBase* m_owner;\n\n\tSenderId m_id;\n\tstd::string m_name;\n\n};\n}\n#endif\n/*EOF*/", class_name);
}

static void generate_replier_source_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sReplier", this_interface);
    
    fprintf(outputfd, "#include \"%s.h\"\n", class_name);
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n");
    fprintf(outputfd, "#include \"%sService.h\"\n", this_interface);
    fprintf(outputfd, "#include \"%sStubBase.h\"\n\n", this_interface);
    fprintf(outputfd, "namespace goni {\n\n");

    fprintf(outputfd, "%s::%s(%sService* owner)\n\t:m_owner(owner)\n{\n}\n", class_name, class_name, this_interface);
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
                fprintf(outputfd, "\tandroid::Parcel _data;\n");
                fprintf(outputfd, "\t_data.writeInt32(id);\n");
                
                arg_type* arg = method->args;
                while (arg)
                {
                    //TYPEMAP* tm = lookup_type(arg->type.type.data);
                    BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->to(1).c_str());
                    arg = arg->next;
                }

                fprintf(outputfd, "\n");
                fprintf(outputfd, "\tm_owner->sendAsyncResponse(id, %sStubBase::NOTIFY_%s, _data);\n\treturn 0;\n}\n", this_interface, makeup(method->name.data).c_str());
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "}\n/* EOF */");

}

static void generate_replier_header_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sReplier", this_interface);
    
    fprintf(outputfd, "#ifndef __%s_H__\n"\
            "#define __%s_H__\n\n", makeup(class_name).c_str(), makeup(class_name).c_str());
    
    fprintf(outputfd, "#include \"StubBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "%s", include_user.c_str());

    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "class %sService;\n\n", this_interface);
    fprintf(outputfd, "class %s\n{\npublic:\n\t%s(%sService* owner);\n\t~%s();\n\n", class_name, class_name, this_interface, class_name);

    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                fprintf(outputfd, "\t%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "\t");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL, "SenderId id");
                fprintf(outputfd, ";\n");
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "\nprivate:\n\t%sService* m_owner;\n};\n}\n#endif\n/* EOF */", this_interface);
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

    fprintf(outputfd, "%s::%s(ServiceBase* owner)\n\t: StubBase(owner)\n\t, m_name(\"%s\")\n{\n", class_name, class_name, this_interface);
    if (multicast_code_count > 0) 
    {
        fprintf(outputfd, "\tm_owner->createPublisher(m_name.c_str());\n");
    }
    fprintf(outputfd, "}\n\n");

    fprintf(outputfd, "%s::~%s()\n{\n", class_name, class_name);
    if (multicast_code_count > 0) 
    {
        fprintf(outputfd, "\tm_owner->destroyPublisher(m_name.c_str());\n");
    }
    fprintf(outputfd, "}\n\n");


    fprintf(outputfd, "int %s::onSyncRequest(unsigned int code, const android::Parcel &data, android::Parcel& _data)\n{\n", class_name);
    fprintf(outputfd, "\tswitch (code) {\n");

    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            if (!method->oneway)
            {
                fprintf(outputfd, "\tcase METHOD_%s:\n\t{\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                char arg_buf[100];
                bzero(arg_buf, sizeof(arg_buf));
                while (arg)
                {
                    BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER)
                    {
                        fprintf(outputfd, bt->from(2).c_str());
                    }
                    else
                    {
                        //TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t");
                        fprintf(outputfd, bt->declare().c_str());
                    }
                        
                    sprintf(arg_buf + strlen(arg_buf), "%s, ", arg->name.data);

                    arg = arg->next;
                }

                if (strlen(arg_buf) != 0)
                {
                    arg_buf[strlen(arg_buf) - 2 ] = 0;
                }

                fprintf(outputfd, "\t\t%s(%s);\n\n", method->name.data, arg_buf);

                arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        //TYPEMAP* tm = lookup_type(arg->type.type.data);
                        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->to(2).c_str());
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\t\tbreak;\n\t}\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "\t}\n\n\treturn 0;\n}\n");
    
    fprintf(outputfd, "int %s::onAsyncRequest(SenderId &id, unsigned int code, const android::Parcel &data)\n{\n", class_name);
    fprintf(outputfd, "\tswitch (code) {\n");

    item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "\tcase COMMAND_%s:\n\t{\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                char arg_buf[100];
                bzero(arg_buf, sizeof(arg_buf));
                sprintf(arg_buf, "id, ");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->from(2).c_str());
                        sprintf(arg_buf + strlen(arg_buf), "%s, ", arg->name.data);

                    }
                    arg = arg->next;
                }

                if (strlen(arg_buf) != 0)
                {
                    arg_buf[strlen(arg_buf) - 2] = 0;
                }

                fprintf(outputfd, "\t\t%s(%s);\n\n", method->name.data, arg_buf);

                fprintf(outputfd, "\t\tbreak;\n\t}\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "\t}\n\n\treturn 0;\n}\n");
            
    item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) {
            multicast_type* method =  (multicast_type*)item;

            make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, class_name);
            fprintf(outputfd, "\n{\n\tandroid::Parcel _data;\n");
            fprintf(outputfd, "\t_data.writeCString(\"%s\");\n", this_interface);
            fprintf(outputfd, "\t_data.writeCString(m_name.data());\n");
            arg_type* arg = method->args;
            while (arg)
            {
                //TYPEMAP* tm = lookup_type(arg->type.type.data);
                BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                fprintf(outputfd, bt->to(1).c_str());

                arg = arg->next;
            }

            fprintf(outputfd, "\n\treturn m_owner->sendMulticast(m_name.c_str(), MULTICAST_%s, _data);\n}\n", makeup(method->name.data).c_str());

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

    fprintf(outputfd, "%s", include_user.c_str());
            

    fprintf(outputfd, "namespace goni {\nclass ServiceBase;\n\n");

    fprintf(outputfd, "class %s : public StubBase\n{\npublic:\n", class_name);
    fprintf(outputfd, "\t%s(ServiceBase* owner);\n\tvirtual ~%s();\n\n", class_name, class_name);

    make_enum_code(outputfd, aitem);

    fprintf(outputfd, "private:\n\
    virtual int onSyncRequest(unsigned int code, const android::Parcel &data,\n\
                              android::Parcel& reply);\n\
    virtual int onAsyncRequest(SenderId &id, unsigned int code,\n\
                               const android::Parcel &data);\n\n");

    fprintf(outputfd, "protected:\n");
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            fprintf(outputfd, "\tvirtual ");
            make_method_name(outputfd, method->name.data, method->type, method->args, method->oneway, NULL);
            fprintf(outputfd, " = 0;\n");
        }
        else if (item->item_type == COMMAND_TYPE)
        {
            command_type* method = (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "\tvirtual ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL, "SenderId id");
                fprintf(outputfd, " = 0;\n");
            }
        }
        else if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;
            fprintf(outputfd, "\t");
            make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
            fprintf(outputfd, ";\n");
        }
        item = item->next;
    }

    fprintf(outputfd, "\nprivate:\n\tstd::string m_name;\n");

    fprintf(outputfd, "};\n}\n#endif\n/* EOF */");
}

static void generate_proxy_source_file(FILE *outputfd, interface_item_type* aitem)
{
    int i = 0;
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sProxyBase", this_interface);

    fprintf(outputfd, "#include \"%s.h\"\n", class_name);
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n\n");
    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "%s::%s(%sProxyReplier* replier)\n\t:ServiceProxyBase(\"%s\")\n\t,m_replier(replier)\n{\n",
            class_name, class_name, this_proxy_interface, this_interface);
    fprintf(outputfd, "\tsetupAsyncRequest();\n}\n");

    fprintf(outputfd, "%s::~%s()\n{\n\tteardownAsyncRequest();\n}\n", class_name, class_name);
    
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
                fprintf(outputfd, "\tandroid::Parcel data, _data;\n");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->to(1).c_str());;
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\tint ret = sendSyncRequest(METHOD_%s, _data, &data);\n", makeup(method->name.data).c_str());
                fprintf(outputfd, "\tif (ret == BS_NO_ERROR) {\n");
                arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER) 
                    {
                        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                        fprintf(outputfd, bt->from(2, false).c_str());;
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, "\t}\n");
                fprintf(outputfd, "\treturn ret;\n}\n");
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
                fprintf(outputfd, "\tandroid::Parcel _data;\n");
                fprintf(outputfd, "\tprepareAsyncData(_data);\n");
                while (arg)
                {
                    BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->to(1).c_str());;
                    arg = arg->next;
                }
                fprintf(outputfd, "\treturn sendAsyncRequest(COMMAND_%s, _data);\n}\n", makeup(method->name.data).c_str());
            }
        }

        item = item->next;
    }

    // async response
    fprintf(outputfd, "int %s::onAsyncResponse(unsigned int code, const android::Parcel &data)\n{\n\tswitch(code) {\n", class_name);
    item = aitem;
    while (item)
    {
        if (item->item_type == COMMAND_TYPE) {
            command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                fprintf(outputfd, "\tcase NOTIFY_%s:\n\t{\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                char arg_buf[100];
                bzero(arg_buf, sizeof(arg_buf));
                while (arg)
                {
                    BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
                    fprintf(outputfd, bt->from(2).c_str());;
                    sprintf(arg_buf + strlen(arg_buf), "%s, ", arg->name.data);
                    arg = arg->next;
                }

                if (strlen(arg_buf) != 0)
                {
                    arg_buf[strlen(arg_buf) - 2 ] = 0;
                }

                fprintf(outputfd, "\t\tm_replier->%s(%s);", method->name.data, arg_buf);
                fprintf(outputfd, "\n\t\tbreak;\n\t}\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "\t}\n\treturn 0;\n}\n");

    fprintf(outputfd, "}\n/* EOF */");
}

static void generate_proxy_header_file(FILE *outputfd, interface_item_type* aitem)
{
    int i;
    interface_item_type* item = aitem;

    fprintf(outputfd, "#ifndef GONI_%s_PROXY_BASE_H\n#define GONI_%s_PROXY_BASE_H\n\n", makeup(this_interface).c_str(), makeup(this_interface).c_str());
    //fprintf(outputfd, "#include <utils/Errors.h>\n");
    fprintf(outputfd, "#include\"servicebase/ServiceProxyBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseDefines.h\"\n\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseGlobal.h\"\n");
    fprintf(outputfd, "%s", include_user.c_str());

    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "class %sProxyReplier\n{\npublic:\n", this_proxy_interface);
    fprintf(outputfd, "\tvirtual ~%sProxyReplier() {}\n\n", this_proxy_interface);

    while (item) 
    {
        if (item->item_type == COMMAND_TYPE) {
            const command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                fprintf(outputfd, "\t%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "\tvirtual ");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
                fprintf(outputfd, " = 0;\n");
            }
        }

        item = item->next;
    }
    fprintf(outputfd, "};\n\n");
    
    fprintf(outputfd, "class %sProxyBase : public ServiceProxyBase\n{\npublic:\n", this_interface);
    make_enum_code(outputfd, aitem, 7);

    fprintf(outputfd, "public:\n");
    fprintf(outputfd, "\t%sProxyBase(%sProxyReplier* replier);\n", this_interface, this_proxy_interface);
    fprintf(outputfd, "\t~%sProxyBase();\n\n", this_interface);

    item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            fprintf(outputfd, "\t%s", gather_comments(method->comments_token->extra).c_str());
            fprintf(outputfd, "\t");
            make_method_name(outputfd, method->name.data, method->type, method->args, method->oneway, NULL);
            fprintf(outputfd, ";\n");
        }
        else if (item->item_type == COMMAND_TYPE) {
            const command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "\t%s", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "\t");
                make_method_name(outputfd, method->name.data, make_void_type(), method->args, false, NULL);
                fprintf(outputfd, ";\n");
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "private:\n" \
                      "\tvirtual int onAsyncResponse(unsigned int code, const android::Parcel &reply);\n\n"\
                      "private:\n"\
                      "\t%sProxyReplier* m_replier;\n", this_proxy_interface);
    
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

    char write_buf[1024];
    char read_buf[1024];
    char init_buf[1024];
    char inc_buf[1024];

    bzero(write_buf, sizeof write_buf);
    bzero(read_buf, sizeof read_buf);
    bzero(init_buf, sizeof init_buf);
    bzero(inc_buf, sizeof inc_buf);


    while (arg) {
        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
        sprintf(read_buf + strlen(read_buf), bt->from(2, false).c_str());
        sprintf(write_buf + strlen(write_buf), bt->to(2).c_str());

        sprintf(init_buf + strlen(init_buf), "\n\t\t%s,", bt->constructor().c_str());
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
    fprintf(outputfd, "%s\n", inc_buf);
    fprintf(outputfd, "namespace goni {\n");
    fprintf(outputfd, "class %s : public android::RefBase\n{\n", p->name.data);
    fprintf(outputfd, "public:\n");

    if (strlen(init_buf) != 0) {
        init_buf[strlen(init_buf) - 1] = 0;
        fprintf(outputfd, "\n\t%s():%s\n\t{\n\t}\n",p->name.data, init_buf);
    }


    arg = p->args;
    while (arg) {
        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
        fprintf(outputfd, "%s", bt->getFunc(1).c_str());
        arg = arg->next;
    }

    fprintf(outputfd, "\tvoid readFromParcel(const android::Parcel& data)\n\t{\n");
    fprintf(outputfd, "%s\t}\n", read_buf);

    fprintf(outputfd, "\tvoid writeToParcel(android::Parcel& _data)\n\t{\n");
    fprintf(outputfd, "%s\t}\n", write_buf);

    fprintf(outputfd, "private:\n");

    arg = p->args;
    while (arg)
    {
        BasicType* bt = BasicTypeFactory::create_type(arg->name.data, arg->type.type.data, arg->type.dimension);
        fprintf(outputfd, "\t%s", gather_comments(arg->type.type.extra).c_str());
        fprintf(outputfd, "\t%s\n", bt->define().c_str());
        arg = arg->next;
    }

    fprintf(outputfd, "\n};\n}\n#endif");
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

// =================================================
int
generate_cpp(const string& filename, const string& originalSrc, document_item_type* docus)
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

    string proxy_str = filename + "/proxy/";
    string stub_str = filename + "/stub/";

    if (access(proxy_str.c_str(), F_OK) != 0) {
        mkdir(proxy_str.c_str(), 0777);
    }
    
    if (access(stub_str.c_str(), F_OK) != 0) {
        mkdir(stub_str.c_str(), 0777);
    }

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

            FILE* outputfd = newfile(proxy_str.c_str(), file_name, ".h", originalSrc);
            generate_proxy_header_file(outputfd, iface->interface_items);
            fclose(outputfd);

            outputfd = newfile(proxy_str.c_str(), file_name, ".cpp", originalSrc);
            generate_proxy_source_file(outputfd, iface->interface_items);
            fclose(outputfd);

            bzero(tmp_file_name, sizeof(tmp_file_name));
            sprintf(tmp_file_name, "%sStubBase", this_interface);
            file_name = std::string(tmp_file_name, strlen(tmp_file_name));

            outputfd = newfile(stub_str.c_str(), file_name, ".h", originalSrc);
            generate_stub_header_file(outputfd, iface->interface_items);
            fclose(outputfd);

            outputfd = newfile(stub_str.c_str(), file_name, ".cpp", originalSrc);
            generate_stub_source_file(outputfd, iface->interface_items);
            fclose(outputfd);

            bzero(tmp_file_name, sizeof(tmp_file_name));
            sprintf(tmp_file_name, "%sReplier", this_interface);
            file_name = std::string(tmp_file_name, strlen(tmp_file_name));

            outputfd = newfile(stub_str.c_str(), file_name, ".h", originalSrc);
            generate_replier_header_file(outputfd, iface->interface_items);
            fclose(outputfd);

            outputfd = newfile(stub_str.c_str(), file_name, ".cpp", originalSrc);
            generate_replier_source_file(outputfd, iface->interface_items);
            fclose(outputfd);

            if (multicast_code_count > 0)
            {
                string sub_str = filename + "/sub/";
                if (access(sub_str.c_str(), F_OK) != 0) {
                    mkdir(sub_str.c_str(), 0777);
                }

                bzero(tmp_file_name, sizeof(tmp_file_name));
                sprintf(tmp_file_name, "%sSub", this_interface);
                file_name = std::string(tmp_file_name, strlen(tmp_file_name));

                outputfd = newfile(sub_str.c_str(), file_name, ".h", originalSrc);
                generate_sub_header_file(outputfd, iface->interface_items);
                fclose(outputfd);

                outputfd = newfile(sub_str.c_str(), file_name, ".cpp", originalSrc);
                generate_sub_source_file(outputfd, iface->interface_items);
                fclose(outputfd);
            }

        }

        docus = docus->next;
    }

    return 0;
}
