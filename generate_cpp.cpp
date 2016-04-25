
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <stdarg.h>
#include <libgen.h>
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
        {"int", "int", "int", "int&", "%s = reply.readInt32();\n", "_data.writeInt32(%s);\n"},
        {"long", "long", "long", "long&", "%s = reply.readInt64();\n", "_data.writeInt64(%s);\n"},
        {"byte", "char", "char", "char&", "%s = reply.readByte();\n", "_data.writeByte(%s);\n"},
        {"boolean", "bool", "bool", "bool&", "%s = reply.readInt32();\n", "_data.writeInt32((int)%s);\n"},
        {"String", "android::String16", "const android::String16&", "android::String16&", "%s = reply.readString16();\n", "_data.writeString16(%s);\n"},
        {"String8", "android::String8", "const android::String8&", "android::String8&", "%s = reply.readString8();\n", "_data.writeString8(%s);\n"},
        {"CString", "android::CString", "const android::CString&", "android::CString&", "%s = reply.readCString();\n", "_data.writeCString(%s);\n"},
        {"IBinder", "android::sp<android::IBinder>", "const android::sp<android::IBinder>&", "android::sp<android::IBinder>&",
            "%s = reply.readStrongBinder();\n", "_data.writeStrongBinder(%s);\n"},
        {"CharSequence", "string", "const string&", "string&", "%s = reply.readstring();\n", "_data.writestring(%s);\n"},
        //{"IBinderThreadPriorityService", "const sp<IBinderThreadPriorityService>&", "sp<IBinderThreadPriorityService>", "sp<IBinderThreadPriorityService>&",
            //"%s = data.readIBinderThreadPriorityService();\n", "_data.writeIBinderThreadPriorityService(%s);\n"},
        //{"WorkSource", "WorkSource", "WorkSource", "WorkSource&", "%s = data.readInt32();\n", "_data.writeInt32(0);\n"},
        {"float", "float", "float", "float&", "%s = reply.readFloat();\n", "_data.writeFloat(%s);\n"},
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

static void make_method_name(FILE* outputfd, method_type* method, char* class_name, bool notify_res = false)
{
    int i = 0;
    string transactCodeName = makeup(method->name.data);
    bool return_void = (strcmp(method->type.type.data, "void") == 0);

    string dimstr;
    for (i=0; i<(int)method->type.dimension; i++)
        dimstr += "[]";

    //fprintf(outputfd, "    virtual ");

    if (return_void)
        fprintf(outputfd, "android::status_t");
    else
        fprintf(outputfd, "%s%s", lookup_type(method->type.type.data)->decl, dimstr.c_str());

    char method_name[100];
    bzero(method_name, sizeof method_name);
    strcpy(method_name, method->name.data);
    if (notify_res)
    {
        strcat(method_name, "_res");
    }

    if (class_name)
        fprintf(outputfd, " %s::%s(", class_name, method_name);
    else
        fprintf(outputfd, " %s(", method_name);

    arg_type* arg = method->args;

    bool first_arg = true;
    while (arg)
    {
        int dir = convert_direction(arg->direction.data);

        if (!notify_res && method->oneway && dir != OUT_PARAMETER)
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

        if (notify_res && method->oneway && dir != IN_PARAMETER)
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

        if (!method->oneway)
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

static void make_enum_code(FILE* outputfd, interface_item_type* aitem)
{
    interface_item_type* item = aitem;
    fprintf(outputfd, "\tenum Method_Code\n\t{\n");
    int enum_count = 0;
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
        fprintf(outputfd, "\t\tMETHOD_MAX\n\t};\n\n");
    else
        fprintf(outputfd, "\t\tMETHOD_MAX = SERVICE_FIRST_TRANSACTION\n\t};\n\n");

    item = aitem;
    fprintf(outputfd, "\tenum Notify_Code\n\t{\n");
    enum_count = 0;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            const method_type* method =  (method_type*)item;
            if (method->oneway)  
            {
                string method_name= makeup(method->name.data);
                fprintf(outputfd, "\t\tNOTIFY_%s", method_name.c_str());
                if (enum_count == 0) 
                {
                    fprintf(outputfd, " = METHOD_MAX + 1,\n");
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

    fprintf(outputfd, "\t\tNOTIFY_MAX\n\t};\n\n");
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
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            if (method->oneway)
            {
                make_method_name(outputfd, method, class_name, true);
                fprintf(outputfd, "\n{\n");
                fprintf(outputfd, "\tandroid::Parcel _data;\n");
                
                arg_type* arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t");
                        fprintf(outputfd, tm->to, arg->name.data);
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\n");
                fprintf(outputfd, "\tm_owner->sendAsyncRes(%sStubBase::NOTIFY_%s, _data);\n\treturn 0;\n}\n", this_interface, makeup(method->name.data).c_str());
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
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            if (method->oneway)
            {
                fprintf(outputfd, "\t");
                make_method_name(outputfd, method, NULL, true);
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
    fprintf(outputfd, "#include \"binder/Parcel.h\"\n\n");
    make_imports(outputfd);
    fprintf(outputfd, "namespace goni {\n\n");

    fprintf(outputfd, "%s::%s() {}\n\n%s::~%s() {}\n\n", class_name, class_name, class_name, class_name);

    fprintf(outputfd, "int %s::onSyncRequest(unsigned int code, const android::Parcel &reply, android::Parcel& _data)\n{\n", class_name);
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
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER)
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s ", tm->decl);
                        fprintf(outputfd, tm->from, arg->name.data);
                    }

                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s %s;\n", tm->decl, arg->name.data);
                    }

                    arg = arg->next;
                }

                fprintf(outputfd, "\t\t%s(", method->name.data);
                arg = method->args;
                bool first_arg = true;
                while (arg)
                {
                    if (first_arg)
                    {
                        fprintf(outputfd, "%s", arg->name.data);
                        first_arg = false;
                    }
                    else
                    {
                        fprintf(outputfd, ", %s", arg->name.data);
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, ");\n\n");

                arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t");
                        fprintf(outputfd, tm->to, arg->name.data);
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\t\tbreak;\n\t}\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "\t}\n\n\treturn 0;\n}\n");
    
    fprintf(outputfd, "int %s::onAsyncRequest(SenderId &id, unsigned int code, const android::Parcel &reply)\n{\n", class_name);
    fprintf(outputfd, "\tswitch (code) {\n");

    item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            if (method->oneway)
            {
                fprintf(outputfd, "\tcase NOTIFY_%s:\n\t{\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s ", tm->decl);
                        fprintf(outputfd, tm->from, arg->name.data);

                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\t\t%s(", method->name.data);
                arg = method->args;
                bool first_arg = true;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        if (first_arg)
                        {
                            fprintf(outputfd, "%s", arg->name.data);
                            first_arg = false;
                        }
                        else
                        {
                            fprintf(outputfd, ", %s", arg->name.data);
                        }
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, ");\n\n");

                fprintf(outputfd, "\t\tbreak;\n\t}\n");
            }
        }

        item = item->next;
    }

    fprintf(outputfd, "\t}\n\n\treturn 0;\n}\n}\n/* EOF */");
}

static void generate_stub_header_file(FILE* outputfd, interface_item_type* aitem)
{
    char class_name[100];
    bzero(class_name, sizeof(class_name));
    sprintf(class_name, "%sStubBase", this_interface);

    fprintf(outputfd, "#ifndef __%s_H__\n"\
            "#define __%s_H__\n\n"\
            "#include \"StubBase.h\"\n" \
            "#include \"binder/Parcel.h\"\n" \
            "#include \"servicebase/ServiceBaseDefines.h\"\n\n" \
            , makeup(class_name).c_str(), makeup(class_name).c_str());
            
    make_imports(outputfd);

    fprintf(outputfd, "namespace goni {\n\n");

    fprintf(outputfd, "class %s : public StubBase\n{\npublic:\n", class_name);
    fprintf(outputfd, "\t%s();\n\tvirtual ~%s();\n\n", class_name, class_name);

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
            make_method_name(outputfd, method, NULL);
            fprintf(outputfd, " = 0;\n");
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
            make_method_name(outputfd, method, class_name);
            fprintf(outputfd, "\n{\n");
                
            arg_type* arg;
            if (method->oneway)
            {
                arg = method->args;
                fprintf(outputfd, "\tandroid::Parcel _data;\n");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        fprintf(outputfd, "\t");
                        fprintf(outputfd, lookup_type(arg->type.type.data)->to, arg->name.data);
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, "\treturn sendAsyncRequest(NOTIFY_%s, _data);\n}\n", makeup(method->name.data).c_str());
            }
            else 
            {
                arg = method->args;
                fprintf(outputfd, "\tandroid::Parcel _data, reply;\n");
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != OUT_PARAMETER) 
                    {
                        fprintf(outputfd, "    ");
                        fprintf(outputfd, lookup_type(arg->type.type.data)->to, arg->name.data);
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
                        fprintf(outputfd, lookup_type(arg->type.type.data)->from, arg->name.data);
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, "\t}\n");
                fprintf(outputfd, "\treturn ret;\n}\n");
            }
        }

        item = item->next;
    }

    // async response
    fprintf(outputfd, "int %s::onAsyncResponse(unsigned int code, const android::Parcel &reply)\n{\n\tswitch(code) {\n", class_name);
    item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;
            if (method->oneway)
            {
                fprintf(outputfd, "\tcase NOTIFY_%s:\n\t{\n", makeup(method->name.data).c_str());
                arg_type* arg = method->args;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        TYPEMAP* tm = lookup_type(arg->type.type.data);
                        fprintf(outputfd, "\t\t%s ", tm->decl);
                        fprintf(outputfd, tm->from, arg->name.data);
                    }
                    arg = arg->next;
                }

                fprintf(outputfd, "\t\tm_replier->%s(", method->name.data);
                arg = method->args;
                bool first_arg = true;
                while (arg)
                {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER)
                    {
                        if (first_arg)
                        {
                            fprintf(outputfd, "%s", arg->name.data);
                            first_arg = false;
                        }
                        else
                        {
                            fprintf(outputfd, ", %s", arg->name.data);
                        }
                    }

                    arg = arg->next;
                }
                fprintf(outputfd, ");\n\t\tbreak;\n\t}\n");
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
        if (item->item_type == METHOD_TYPE) {
            const method_type* method =  (method_type*)item;
            if (method->oneway) 
            {
                string transactCodeName = makeup(method->name.data);
                bool return_void = (strcmp(method->type.type.data, "void") == 0);

                string dimstr;
                for (i=0; i<(int)method->type.dimension; i++)
                    dimstr += "[]";
                fprintf(outputfd, "    virtual ");
                if (return_void)
                    fprintf(outputfd, "android::status_t");
                else
                    fprintf(outputfd, "%s%s", lookup_type(method->type.type.data)->decl, dimstr.c_str());
                fprintf(outputfd, " %s(", method->name.data);
                arg_type* arg = method->args;
                bool first_arg = true;
                while (arg) {
                    if (convert_direction(arg->direction.data) != IN_PARAMETER) 
                    {
                        if (first_arg)
                        {
                            fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
                            first_arg = false;
                        }
                        else
                            fprintf(outputfd, " ,%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, ") = 0;\n");

            }
        }
        item = item->next;
    }
    fprintf(outputfd, "};\n\n");
    
    fprintf(outputfd, "class %sProxyBase : public ServiceProxyBase\n{\npublic:\n", this_interface);
    make_enum_code(outputfd, aitem);

    fprintf(outputfd, "public:\n");
    fprintf(outputfd, "\t%sProxyBase(%sProxyReplier* replier);\n", this_interface, this_proxy_interface);
    fprintf(outputfd, "\t~%sProxyBase();\n\n", this_interface);

    item = aitem;
    while (item)
    {
        if (item->item_type == METHOD_TYPE) {
            method_type* method =  (method_type*)item;

            fprintf(outputfd, "\t");
            make_method_name(outputfd, method, NULL);
            fprintf(outputfd, ";\n");
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

static void generate_header_file(FILE *outputfd, interface_item_type* aitem)
{
    interface_item_type* item = aitem;
    fprintf(outputfd, "#ifndef ANDROID_%s_H\n#define ANDROID_%s_H\n\n", makeup(this_proxy_interface).c_str(), makeup(this_proxy_interface).c_str());
    //fprintf(outputfd, "#include <utils/Errors.h>\n");
    fprintf(outputfd, "#include\"servicebase/ServiceProxyBase.h\"\n");
    fprintf(outputfd, "#include \"servicebase/ServiceBaseDefines.h\"\n\n");
    make_imports(outputfd);

    fprintf(outputfd, "namespace goni {\n\n");
    fprintf(outputfd, "class %sProxy : public ServiceProxyBase\n{\npublic:\n", this_proxy_interface);
    //fprintf(outputfd, "    DECLARE_META_INTERFACE(%s);\n", this_interface);
    while (item) {
        if (item->item_type == METHOD_TYPE) {
            int i;
            const method_type* method =  (method_type*)item;
            if (!method->oneway) 
            {
                string transactCodeName = makeup(method->name.data);
                bool return_void = (strcmp(method->type.type.data, "void") == 0);

                string dimstr;
                for (i=0; i<(int)method->type.dimension; i++)
                    dimstr += "[]";
                fprintf(outputfd, "    virtual ");
                if (return_void)
                    fprintf(outputfd, "android::status_t");
                else
                    fprintf(outputfd, "%s%s", lookup_type(method->type.type.data)->decl, dimstr.c_str());
                fprintf(outputfd, " %s(", method->name.data);
                arg_type* arg = method->args;
                while (arg) {
                    fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
                    arg = arg->next;
                    if (arg)
                        fprintf(outputfd, ", ");
                }
                fprintf(outputfd, ");\n");
            }
        }
        item = item->next;
    }
    fprintf(outputfd, "};\n\n");

#if 0
    fprintf(outputfd, "class Bn%s : public BnInterface<%s>\n{\npublic:\n", this_interface, this_proxy_interface);
    fprintf(outputfd, "    enum {\n");
    item = aitem;
    int once = 1;
    while (item) {
        if (item->item_type == METHOD_TYPE)
            fprintf(outputfd, "        %s", makeup(((method_type*)item)->name.data).c_str());
        if (once)
            fprintf(outputfd, " = IBinder::FIRST_CALL_TRANSACTION");
        once = 0;
        fprintf(outputfd, ",\n");
        item = item->next;
    }
    fprintf(outputfd, "    };\n");
    fprintf(outputfd, "    virtual status_t onTransact(uint32_t code, const Parcel& data,\n        Parcel *reply, uint32_t flags);\n");
    fprintf(outputfd, "};\n");
    fprintf(outputfd, "}; // namespace android\n\n#endif // ANDROID_%s_H\n", makeup(this_proxy_interface).c_str());
#endif
}

static void generate_implementation(FILE *outputfd, interface_item_type* aitem)
{
    interface_item_type* item = aitem;
    fprintf(outputfd, "#define LOG_TAG \"%s\"\n", this_interface);
    fprintf(outputfd, "//#define LOG_NDEBUG 0\n\n");
    //fprintf(outputfd, "#include <utils/Log.h>\n");
    //fprintf(outputfd, "#include <stdint.h>\n");
    //fprintf(outputfd, "#include <sys/types.h>\n");
    fprintf(outputfd, "#include <binder/Parcel.h>\n");
    fprintf(outputfd, "#include <%s/%s.h>\n\n", makelow(this_interface).c_str(), this_proxy_interface);
    make_imports(outputfd);
    fprintf(outputfd, "namespace goni {\n\n");
    //fprintf(outputfd, "class Bp%s : public BpInterface<%s>\n{\n",
    //this_interface, this_proxy_interface);
    //fprintf(outputfd, "    public:\n");
    //fprintf(outputfd, "    Bp%s(const sp<IBinder>& impl)\n        : BpInterface<%s>(impl) { }\n",
    //this_interface, this_proxy_interface);
    while (item) {
        if (item->item_type == METHOD_TYPE) {
            const method_type* method = (method_type*)item;

            if (!method->oneway) 
            {
                bool return_void = (strcmp(method->type.type.data, "void") == 0);
                string transactCodeName = "::" + makeup(method->name.data);
                transactCodeName = this_interface + transactCodeName;
                //transactCodeName = "Bn" + transactCodeName;
                string dimstr;
                for (int i=0; i<(int)method->type.dimension; i++)
                    dimstr += "[]";
                fprintf(outputfd, "%s\n", gather_comments(method->comments_token->extra).c_str());
                fprintf(outputfd, "virtual ");
                if (return_void)
                    fprintf(outputfd, "android::status_t");
                else
                    fprintf(outputfd, "%s%s", lookup_type(method->type.type.data)->decl, dimstr.c_str());
                fprintf(outputfd, " %sProxy::%s(",this_interface, method->name.data);
                arg_type* arg = method->args;
                while (arg) {
                    fprintf(outputfd, "%s %s", lookup_type(arg->type.type.data)->declparam, arg->name.data);
                    arg = arg->next;
                    if (arg)
                        fprintf(outputfd, ", ");
                }
                fprintf(outputfd, ")\n{\n    Parcel _data, reply;\n");
                fprintf(outputfd, "   _data.writeInterfaceToken(%s::getInterfaceDescriptor());\n", this_proxy_interface);
                arg = method->args;
                while (arg) {
                    int dir = convert_direction(arg->direction.data);
                    if (dir == OUT_PARAMETER && arg->type.dimension) {
                        printf("[%s:%d] out + dim not supported\n", __FUNCTION__, __LINE__);
                        //exit(1);
                    }
                    else if (dir & IN_PARAMETER) {
                        fprintf(outputfd, "    ");
                        fprintf(outputfd, lookup_type(arg->type.type.data)->to, arg->name.data);
                    }
                    arg = arg->next;
                }
                fprintf(outputfd, "    ");
                if (return_void)
                    fprintf(outputfd, "return ");
                //fprintf(outputfd, "remote()->transact(%s, _data, &reply)", transactCodeName.c_str());
                fprintf(outputfd, "sendSyncRequest(%s, _data, &reply)", transactCodeName.c_str());
                if (!return_void) {
                    fprintf(outputfd, ";\n    // fail on exception\n    if (reply.readExceptionCode() != 0) return 0;\n    return reply.readInt32()");
                }
                fprintf(outputfd, ";\n}\n");
            }
        }
        item = item->next;
    }

#if 0
    fprintf(outputfd, "};\n\nIMPLEMENT_META_INTERFACE(%s, \"android.os.%s\");\n", this_interface, this_proxy_interface);
    item = aitem;
    //fprintf(outputfd, "static char const* getServiceName() { return \"%s\"; }\n", this_proxy_interface);
    fprintf(outputfd, "\nstatus_t Bn%s::onTransact(uint32_t code, const Parcel& data, Parcel *reply, uint32_t flags)\n{\n", this_interface);
    fprintf(outputfd, "switch (code) {\n");
    while (item) {
        if (item->item_type == METHOD_TYPE) {
            int argindex = 0;
            const method_type* method =  (method_type*)item;
            string transactCodeName = makeup(method->name.data);
            bool return_void = (strcmp(method->type.type.data, "void") == 0);

            fprintf(outputfd, "case %s: {\n", transactCodeName.c_str());
            fprintf(outputfd, "    CHECK_INTERFACE(%s, data, reply);\n", this_proxy_interface);
            arg_type* arg = method->args;
            while (arg) {
                char thisname[100];
                sprintf(thisname, "_arg%d", argindex);
                TYPEMAP* tp = lookup_type(arg->type.type.data);
                fprintf(outputfd, "    %s %s;\n", tp->decl, thisname);
                if (convert_direction(arg->direction.data) & IN_PARAMETER) {
                    fprintf(outputfd, "    ");
                    fprintf(outputfd, tp->from, thisname);
                }
#if 0
                else if (arg->type.dimension == 0) {
                    printf("[%s:%d]\n", __FUNCTION__, __LINE__);
                    exit(1);
                }
                else if (arg->type.dimension == 1) {
                    printf("[%s:%d]\n", __FUNCTION__, __LINE__);
                    exit(1);
                }
#endif
#if 0
                else
                    fprintf(stderr, "aidl:OUT param %s:%d\n", __FILE__, __LINE__);
#endif
                arg = arg->next;
                argindex++;
            }
            fprintf(outputfd, "    ");
            if (!return_void)
                fprintf(outputfd, "int res = ");
            fprintf(outputfd, "%s(", method->name.data);
            int i = 0;
            while (argindex-- > 0) {
                fprintf(outputfd, "_arg%d", i++);
                if (argindex > 0)
                    fprintf(outputfd, ", ");
            }
            fprintf(outputfd, ")");
            if (!strcmp(method->type.type.data, "boolean"))
                fprintf(outputfd, "? 1 : 0");
            fprintf(outputfd, ";\n");
            if (!return_void)
                fprintf(outputfd, "    reply->writeNoException();\n    reply->writeInt32(res);\n");
            // out parameters
            argindex = 0;
            arg = method->args;
            while (arg) {
                if (convert_direction(arg->direction.data) & OUT_PARAMETER)
                    fprintf(outputfd, "data.%s(%s);\n", lookup_type(arg->type.type.data)->to, arg->name.data);
                argindex++;
                arg = arg->next;
            }
            fprintf(outputfd, "    return NO_ERROR;\n    }\n");
        }
        item = item->next;
    }
    fprintf(outputfd, "}\nreturn BBinder::onTransact(code, data, reply, flags);\n}\n");
    fprintf(outputfd, "\n}; // namespace android\n");
#endif
}

static FILE *newfile(char *filebuff, const string& filename, const char *suffix, const string& originalSrc)
{
    strcpy(filebuff, this_interface);
    dirname(filebuff);
    strcat(filebuff, "/");
    strcat(filebuff, filename.c_str());
    strcat(filebuff, suffix);
    //printf("outputting... filename=%s\n", filebuff);
    FILE* outputfd = fopen(filebuff, "wb");
    if (!outputfd) {
        fprintf(stderr, "unable to open %s for write\n", filebuff);
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
    /* open file in binary mode to ensure that the tool produces the
     * same output on all platforms !!
     */
    //char *filebuff = (char *)malloc(strlen(filename.c_str()) + strlen(this_proxy_interface) + 50);

    //printf("[%s:%d] starting\n", __FUNCTION__, __LINE__);
    //FILE *outputfd = newfile(filebuff, filename, ".h", originalSrc);
    //generate_header_file(outputfd, iface->interface_items);
    //fclose(outputfd);
    //outputfd = newfile(filebuff, filename, ".cpp", originalSrc);
    //generate_implementation(outputfd, iface->interface_items);
    //fclose(outputfd);
    //
    // generate proxy header file
    char tmp_file_name[100];
    memset(tmp_file_name, 0, sizeof(tmp_file_name));

    char filebuff[1024];
    sprintf(tmp_file_name, "%sProxyBase", this_interface);
    std::string file_name(tmp_file_name, strlen(tmp_file_name));

    FILE* outputfd = newfile(filebuff, file_name, ".h", originalSrc);
    generate_proxy_header_file(outputfd, iface->interface_items);
    fclose(outputfd);

    outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
    generate_proxy_source_file(outputfd, iface->interface_items);
    fclose(outputfd);
    
    sprintf(tmp_file_name, "%sStubBase", this_interface);
    file_name = std::string(tmp_file_name, strlen(tmp_file_name));

    outputfd = newfile(filebuff, file_name, ".h", originalSrc);
    generate_stub_header_file(outputfd, iface->interface_items);
    fclose(outputfd);

    outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
    generate_stub_source_file(outputfd, iface->interface_items);
    fclose(outputfd);

    sprintf(tmp_file_name, "%sReplier", this_interface);
    file_name = std::string(tmp_file_name, strlen(tmp_file_name));

    outputfd = newfile(filebuff, file_name, ".h", originalSrc);
    generate_replier_header_file(outputfd, iface->interface_items);
    fclose(outputfd);
    
    outputfd = newfile(filebuff, file_name, ".cpp", originalSrc);
    generate_replier_source_file(outputfd, iface->interface_items);
    fclose(outputfd);

    return 0;
}
