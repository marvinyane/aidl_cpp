
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
#include "generate_java.h" // for gather_comments()

using namespace std;

extern import_info* g_imports;

typedef struct {
    const char *name;
    const char *decl;
    const char *declparam;
    const char *writeparam;
    const char *from;
    const char *to;
} TYPEMAP;

static const char *this_proxy_interface;
static const char *this_interface;

static TYPEMAP* lookup_type(const char *name)
{
    static TYPEMAP typemap[] = {
        {"int", "int", "int", "int&", "%s = %sreadInt32();\n", "%swriteInt32(%s);\n"},
        {"long", "long", "long", "long&", "%s = %sreadInt64();\n", "%swriteInt64(%s);\n"},
        {"byte", "char", "char", "char&", "%s = %sreadByte();\n", "%swriteByte(%s);\n"},
        {"boolean", "bool", "bool", "bool&", "%s = %sreadInt32();\n", "%swriteInt32((int)%s);\n"},
        {"String", "android::String16", "const android::String16&", "android::String16&", "%s = %sreadString16();\n", "%swriteString16(%s);\n"},
        {"String8", "android::String8", "const android::String8&", "android::String8&", "%s = %sreadString8();\n", "%swriteString8(%s);\n"},
        {"CString", "android::CString", "const android::CString&", "android::CString&", "%s = %sreadCString();\n", "%swriteCString(%s);\n"},
        {"IBinder", "android::sp<android::IBinder>", "const android::sp<android::IBinder>&", "android::sp<android::IBinder>&",
            "%s = %sreadStrongBinder();\n", "%swriteStrongBinder(%s);\n"},
        {"CharSequence", "string", "const string&", "string&", "%s = %sreadstring();\n", "%swritestring(%s);\n"},
        //{"IBinderThreadPriorityService", "const sp<IBinderThreadPriorityService>&", "sp<IBinderThreadPriorityService>", "sp<IBinderThreadPriorityService>&",
            //"%s = data.readIBinderThreadPriorityService();\n", "%swriteIBinderThreadPriorityService(%s);\n"},
        //{"WorkSource", "WorkSource", "WorkSource", "WorkSource&", "%s = data.readInt32();\n", "%swriteInt32(0);\n"},
        {"float", "float", "float", "float&", "%s = %sreadFloat();\n", "%swriteFloat(%s);\n"},
        {0, 0, 0, 0, 0, 0}};

    static TYPEMAP pattern =
    {"%s", "const android::sp<%s>&", "const android::sp<%s>&", "android::sp<%s>", "%%s = data.readStrong%s();\n", "%%s.writeToParcel(&_data);\n"};
    static char temps[6][100];
    static TYPEMAP temp = {(const char *)temps[0], (const char *)temps[1], (const char *)temps[2], (const char *)temps[3], (const char *)temps[4], (const char*)temps[5]};

    TYPEMAP *p = typemap;
    while (p->name && strcmp(name, p->name))
        p++;
    if (!p->name) {
        sprintf(temps[0], pattern.name, name);
        sprintf(temps[1], pattern.decl, name);
        sprintf(temps[2], pattern.declparam, name);
        sprintf(temps[3], pattern.writeparam, name);
        sprintf(temps[4], pattern.from, name);
        sprintf(temps[5], pattern.to, name);
        return &temp;
#if 0
        printf ("lookup_type: failed to find '%s'\n", name);
        exit(1);
        return NULL;
#endif
    }
    return p;
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

static void make_imports(FILE* outputfd)
{
    import_info* imports = g_imports;

    while (imports)
    {
        char header_name[100];
        bzero(header_name, sizeof header_name);
        int i = 0;
        for (; i < strlen(imports->neededClass); i++)
        {
            if (imports->neededClass[i] == '.')
            {
                header_name[i] = '/';
            }
            else
            {
                header_name[i] = imports->neededClass[i];
            }
        }

        fprintf(outputfd, "#include \"%s.h\"\n", header_name);

        imports = imports->next;
    }
}

static void make_method_name(FILE* outputfd,
        char* method_name_data, type_type type, arg_type* method_args, bool oneway,
        char* class_name, char* arg_pre = NULL)
{
    int i = 0;
    string transactCodeName = makeup(method_name_data);
    bool return_void = (strcmp(type.type.data, "void") == 0);

    string dimstr;
    for (i=0; i<(int)type.dimension; i++)
        dimstr += "[]";

    //fprintf(outputfd, "    virtual ");

    if (return_void)
        fprintf(outputfd, "android::status_t");
    else
        fprintf(outputfd, "%s%s", lookup_type(type.type.data)->decl, dimstr.c_str());

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

            fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
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
                fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
            else
                fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->writeparam, arg->name.data);
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
    "\t: m_replier(replier)\n"\
    "\t, m_owner(owner)\n"\
    "\t, m_name(\"%s\")\n{\n"\
    "\tm_owner->addSubscriber(\"%s\", m_name.c_str(), m_id);\n}\n\n"\
    "%s::~%s()\n{\n"\
    "\tm_owner->removeSubscriber(\"%s\", m_name.c_str());\n}\n\n",
    class_name, class_name, class_name, class_name,this_interface, this_interface, class_name, class_name, this_interface);
 

    fprintf(outputfd, "int %s::onMultiCast(unsigned int code, const android::Parcel &data)\n{\n\tswitch(code) {\n", class_name);
    
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
                TYPEMAP* tm = lookup_type(arg->type.type.data);
                fprintf(outputfd, "\t\t%s ", tm->decl);
                fprintf(outputfd, tm->from, arg->name.data, "data.");

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
    fprintf(outputfd, "#include \"servicebase/ServiceBaseDefines.h\"\n");

    fprintf(outputfd, "namespace goni {\nclass ServiceBase;\n\n");
    fprintf(outputfd, "class I%s\n{\npublic:\n\tvirtual ~I%s() {}\n\n", class_name, class_name);
    
    interface_item_type* item = aitem;
    while (item)
    {
        if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;
            type_type type;
            type.type.data = "void";
            fprintf(outputfd, "\tvirtual ");
            make_method_name(outputfd, method->name.data, type, method->args, false, NULL);
            fprintf(outputfd, " = 0;\n");
        }
        item = item->next;
    }

    fprintf(outputfd, "\n};\n\n");

    fprintf(outputfd, "class %s\n{\n\tpublic:", class_name);

    make_enum_code(outputfd, aitem, 8);

    fprintf(outputfd, "public:\n\t%s(I%s* replier, ServiceBase* owner);\n\t~%s();\n\n", class_name, class_name, class_name);
    fprintf(outputfd, "\tint onMultiCast(unsigned int code, const android::Parcel &data);\n\n");

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
    make_imports(outputfd);
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
                type_type type;
                type.type.data = "void";
                make_method_name(outputfd, method->name.data, type, method->args, false, class_name, "SenderId id");
                fprintf(outputfd, "\n{\n");
                fprintf(outputfd, "\tandroid::Parcel _data;\n");
                fprintf(outputfd, "\t_data.writeInt32(id);\n");
                
                arg_type* arg = method->args;
                while (arg)
                {
                    TYPEMAP* tm = lookup_type(arg->type.type.data);
                    fprintf(outputfd, "\t");
                    fprintf(outputfd, tm->to, "_data.", arg->name.data);
                    arg = arg->next;
                }

                fprintf(outputfd, "\n");
                fprintf(outputfd, "\tm_owner->sendAsyncRes(id, %sStubBase::NOTIFY_%s, _data);\n\treturn 0;\n}\n", this_interface, makeup(method->name.data).c_str());
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
    make_imports(outputfd);

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
                type_type type;
                type.type.data = "void";
                fprintf(outputfd, "\t");
                make_method_name(outputfd, method->name.data, type, method->args, false, NULL, "SenderId id");
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
    make_imports(outputfd);
    fprintf(outputfd, "namespace goni {\n\n");

    fprintf(outputfd, "%s::%s(ServiceBase* owner)\n\t: StubBase(owner)\n\t, m_name(\"AAA\")\n{\n", class_name, class_name);
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


    fprintf(outputfd, "int %s::onSyncRequest(unsigned int code, const android::Parcel &data, android::Parcel& reply)\n{\n", class_name);
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
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER)
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s ", tm->decl);
                        fprintf(outputfd, tm->from, arg->name.data, "data.");
                    }
                    else
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s %s;\n", tm->decl, arg->name.data);
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
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t");
                        fprintf(outputfd, tm->to, "reply.", arg->name.data);
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
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s ", tm->decl);
                        fprintf(outputfd, tm->from, arg->name.data, "data.");
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
            type_type type;
            type.type.data = "void";

            make_method_name(outputfd, method->name.data, type, method->args, false, class_name);
            fprintf(outputfd, "\n{\n\tandroid::Parcel _data;\n");
            fprintf(outputfd, "\t_data.writeCString(\"%s\");\n", this_interface);
            fprintf(outputfd, "\t_data.writeCString(m_name.data());\n");
            arg_type* arg = method->args;
            while (arg)
            {
                TYPEMAP* tm = lookup_type(arg->type.type.data);
                fprintf(outputfd, "\t");
                fprintf(outputfd, tm->to, "_data.", arg->name.data);

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
            , makeup(class_name).c_str(), makeup(class_name).c_str());
            
    make_imports(outputfd);

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
            type_type type;
            type.type.data = "void";

            command_type* method = (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                fprintf(outputfd, "\tvirtual ");
                make_method_name(outputfd, method->name.data, type, method->args, false, NULL, "SenderId id");
                fprintf(outputfd, " = 0;\n");
            }
        }
        else if (item->item_type == MULTICAST_TYPE) 
        {
            multicast_type* method =  (multicast_type*)item;
            type_type type;
            type.type.data = "void";
            fprintf(outputfd, "\t");
            make_method_name(outputfd, method->name.data, type, method->args, false, NULL);
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
    make_imports(outputfd);
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
                fprintf(outputfd, "\tandroid::Parcel _data, reply;\n");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        fprintf(outputfd, "    ");
                        fprintf(outputfd, lookup_type(arg->type.type.data)->to, "_data.", arg->name.data);
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\tint ret = sendSyncRequest(METHOD_%s, _data, &reply);\n", makeup(method->name.data).c_str());
                fprintf(outputfd, "\tif (ret == BS_NO_ERROR) {\n");
                arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER) 
                    {
                        fprintf(outputfd, "\t\t");
                        fprintf(outputfd, lookup_type(arg->type.type.data)->from, arg->name.data, "reply.");
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
                type_type type;
                type.type.data = "void";

                make_method_name(outputfd, method->name.data, type, method->args, false, class_name);
                fprintf(outputfd, "\n{\n");
                arg_type* arg = method->args;
                fprintf(outputfd, "\tandroid::Parcel _data;\n");
                fprintf(outputfd, "\tprepareAsyncData(_data);\n");
                while (arg)
                {
                    fprintf(outputfd, "\t");
                    fprintf(outputfd, lookup_type(arg->type.type.data)->to, "_data.", arg->name.data);
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
                    TYPEMAP* tm = lookup_type(arg->type.type.data);
                    fprintf(outputfd, "\t\t%s ", tm->decl);
                    fprintf(outputfd, tm->from, arg->name.data, "data.");
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
    make_imports(outputfd);

    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "class %sProxyReplier\n{\npublic:\n", this_proxy_interface);
    fprintf(outputfd, "\tvirtual ~%sProxyReplier() {}\n\n", this_proxy_interface);

    while (item) 
    {
        if (item->item_type == COMMAND_TYPE) {
            const command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == OUT_PARAMETER)
            {
                type_type type;
                type.type.data = "void";
                fprintf(outputfd, "\tvirtual ");
                make_method_name(outputfd, method->name.data, type, method->args, false, NULL);
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
            fprintf(outputfd, "\t");
            make_method_name(outputfd, method->name.data, method->type, method->args, method->oneway, NULL);
            fprintf(outputfd, ";\n");
        }
        else if (item->item_type == COMMAND_TYPE) {
            const command_type* method =  (command_type*)item;
            if (convert_direction(method->direction.data) == IN_PARAMETER)
            {
                type_type type;
                type.type.data = "void";
                fprintf(outputfd, "\t");
                make_method_name(outputfd, method->name.data, type, method->args, false, NULL);
                fprintf(outputfd, ";\n");
            }
        }
        item = item->next;
    }

    fprintf(outputfd, "private:\n" \
                      "\tvirtual int onAsyncResponse(unsigned int code, const android::Parcel &reply);\n\n"\
                      "private:\n"\
                      "\tIAAAProxyReplier* m_replier;\n");
    
    fprintf(outputfd, "};\n}\n");

    fprintf(outputfd, "#endif\n/* EOF */");
}

static FILE *newfile(const char *filebuff, const string& filename, const char *suffix, const string& originalSrc)
{
    char tmp_buf[1024];
    bzero(tmp_buf, sizeof(tmp_buf));
    strcpy(tmp_buf, filebuff);
    strcat(tmp_buf, filename.c_str());
    strcat(tmp_buf, suffix);
    //printf("outputting... filename=%s\n", filebuff);
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
generate_cpp(const string& filename, const string& originalSrc, interface_type* iface)
{
    if (filename == "-") {
        printf("[%s:%d] stdout not supported!!\n", __FUNCTION__, __LINE__);
        exit(1);
    }
    if (iface->document_item.item_type != INTERFACE_TYPE_BINDER) {
        printf("[%s:%d] error, no %d support yet!!!!!\n", __FUNCTION__, __LINE__, iface->document_item.item_type);
        exit(1);
    }

    this_proxy_interface = iface->name.data;
    this_interface = &this_proxy_interface[1];
    
    char tmp_file_name[100];
    char filebuff[1024];

    if (access(this_interface, F_OK) == 0) {
        char cmd[100];
        sprintf(cmd, "rm -rf %s", this_interface);
        system(cmd);
    }
    
    mkdir(this_interface, 0777);

    memset(filebuff, 0, sizeof(filebuff));
    sprintf(filebuff, "%s/proxy/", this_interface);
    mkdir(filebuff, 0777);

    bzero(tmp_file_name, sizeof(tmp_file_name));
    sprintf(tmp_file_name, "%sProxyBase", this_interface);
    std::string file_name(tmp_file_name, strlen(tmp_file_name));

    FILE* outputfd = newfile(filebuff, file_name, ".h", originalSrc);
    generate_proxy_header_file(outputfd, iface->interface_items);
    fclose(outputfd);

    outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
    generate_proxy_source_file(outputfd, iface->interface_items);
    fclose(outputfd);
    
    // create stub 
    memset(filebuff, 0, sizeof(filebuff));
    sprintf(filebuff, "%s/stub/", this_interface);
    mkdir(filebuff, 0777);

    bzero(tmp_file_name, sizeof(tmp_file_name));
    sprintf(tmp_file_name, "%sStubBase", this_interface);
    file_name = std::string(tmp_file_name, strlen(tmp_file_name));

    outputfd = newfile(filebuff, file_name, ".h", originalSrc);
    generate_stub_header_file(outputfd, iface->interface_items);
    fclose(outputfd);

    outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
    generate_stub_source_file(outputfd, iface->interface_items);
    fclose(outputfd);

    bzero(tmp_file_name, sizeof(tmp_file_name));
    sprintf(tmp_file_name, "%sReplier", this_interface);
    file_name = std::string(tmp_file_name, strlen(tmp_file_name));

    outputfd = newfile(filebuff, file_name, ".h", originalSrc);
    generate_replier_header_file(outputfd, iface->interface_items);
    fclose(outputfd);
    
    outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
    generate_replier_source_file(outputfd, iface->interface_items);
    fclose(outputfd);

    if (multicast_code_count > 0) 
    {
        // create sub
        memset(filebuff, 0, sizeof(filebuff));
        sprintf(filebuff, "%s/sub/", this_interface);
        mkdir(filebuff, 0777);

        bzero(tmp_file_name, sizeof(tmp_file_name));
        sprintf(tmp_file_name, "%sSub", this_interface);
        file_name = std::string(tmp_file_name, strlen(tmp_file_name));

        outputfd = newfile(filebuff, file_name, ".h", originalSrc);
        generate_sub_header_file(outputfd, iface->interface_items);
        fclose(outputfd);

        outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
        generate_sub_source_file(outputfd, iface->interface_items);
        fclose(outputfd);
    }
    return 0;
}
