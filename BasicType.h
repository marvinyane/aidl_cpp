#ifndef __BASICTYPE_H__
#define __BASICTYPE_H__

#include <stdio.h>
#include <strings.h>

#include <string>
#include <vector>

class BasicType
{
public:
    BasicType(std::string name, std::string type, bool is_array = false)
        : m_name(name)
        , m_type(type)
        , m_array(is_array)
        , m_localType(type)
        , m_readParcel("readInt32")
        , m_writeParcel("writeInt32")
    {
        if (is_array) {
            std::string tmp("std::vector<");
            tmp.append(type);
            tmp.append(">");

            m_type = tmp;
        }
    }

    ~BasicType(){}

    virtual bool basicType()
    {
        return true;
    }

    std::string format(const std::string& _f, int tab_size)
    {
        std::string ret;

        std::string tab;
        for (int i = 0; i < tab_size; i++)
            tab.push_back('\t');

        ret.append(tab);
        bool new_line = false;
        for (int i = 0; i < _f.size(); i++)
        {
            ret.push_back(_f[i]);
            if (_f[i] == '{')
                tab.push_back('\t');
            if (_f[i] == '}')
                tab.erase(0, 1);

            if (_f[i] == '\n' && i != _f.size() - 1)
            {
                if (_f[i+1] == '}')
                {
                    tab.erase(0, 1);
                    ret.append(tab);
                    ret.push_back('}');
                    i++;
                }
                else
                {
                    ret.append(tab);
                }
            }
        }

        return ret;
    }

    /*
     * a()
     */
    virtual std::string constructor()
    {
        std::string tmp(m_name);
        tmp.append("()");

        return tmp;
    }

    std::string upFirst(const std::string& name )
    {
        std::string tmp (name);
        tmp[0] = toupper(tmp[0]);
        return tmp;
    }

    virtual std::string getFunc(int tab_size = 0)
    {
        std::string tmp("const ");
        tmp.append(m_type);
        tmp.append("& get");
        tmp.append(upFirst(m_name));
        tmp.append("() { return ");
        tmp.append(m_name);
        tmp.append("; }\n");

        tmp.append("void set");
        tmp.append(upFirst(m_name));
        tmp.append("(");
        tmp.append("const ");
        tmp.append(m_type);
        tmp.append("& _");
        tmp.append(m_name);
        tmp.append(") {");
        tmp.append(m_name);
        tmp.append(" = _");
        tmp.append(m_name);
        tmp.append("; }\n\n");

        return format(tmp, tab_size);
    }

    /*
     * int a;
     * std::vector<int> a;
     */
    virtual std::string declare(const char* v = NULL)
    {
        std::string tmp;
        tmp.append(m_type);
        tmp.append(" ");
        if (v) {
            tmp.append(v);
        }
        else {
            tmp.append(m_name);
        }
        tmp.append(";\n");

        return tmp;
    }

    virtual std::string define(int tab_size = 0)
    {
        std::string tmp;
        tmp.append(m_type);
        tmp.append(" ");
        tmp.append(m_name);

        tmp.append(";\n");
        return format(tmp, tab_size);
    }

    /*
     * const int& a
     * const std::vector<int>& a
     */
    virtual std::string declparam()
    {
        std::string tmp;
        tmp.append("const ");
        tmp.append(m_type);
        tmp.append("& ");
        tmp.append(m_name);
        tmp.append(" ");


        return tmp;
    }

    /*
         * int& a
         * std::vector<int>& a
         */
    virtual std::string writeparam()
    {
        std::string tmp;

        tmp.append(m_type);
        tmp.append("& ");
        tmp.append(m_name);
        tmp.append(" ");

        return tmp;
    }

    /*
         * a = data.readInt32();
         * {
         * int _len = data.readInt32();
         * for (int i = 0; i < len; i++) {
         *     int _tmp = data.readInt32();
         *     a.push_back(_tmp);
         * }
         * }
         */
    virtual std::string from(int tab_size, bool decl = true)
    {
        std::string tmp;

        if (m_array) {
            if (decl)
                tmp.append(declare());

            tmp.append("{\n");
            tmp.append("int _len = data.readInt32();\n");
            tmp.append("for (int i = 0; i < _len; i++) {\n");
            tmp.append(m_localType);
            tmp.append(" _tmp = data.");
            tmp.append(m_readParcel);
            tmp.append("();\n");
            tmp.append(m_name);
            tmp.append(".push_back(_tmp);\n}\n}\n");
        }
        else {
            if (decl)
            {
                tmp.append(m_type);
                tmp.append(" ");
            }
            tmp.append(m_name);
            tmp.append(" = data.");
            tmp.append(m_readParcel);
            tmp.append("();\n");
        }
    
        return format(tmp, tab_size);
    }

    /*
         * _data.writeInt32(a);
         * {
         * _data.writeInt32(a.length());
         * std::vector<int>::iterator it = a.begin();
         * for (; it != a.end(); it++) {
         *     _data.readInt32(*it);
         * }
         * }
         */
    virtual std::string to(int tab_size, bool decl = false)
    {
        std::string tmp;
        if (decl) 
            tmp.append(declare());

        if (m_array) {
            char tt[1024];
            bzero(tt, sizeof tt);
            sprintf(tt, "{\n_data.writeInt32(%s.size());\n"\
                    "%s::const_iterator it = %s.begin();\n"\
                    "for (; it != %s.end(); it++) {\n"\
                    "_data.%s(*it);\n}\n}\n",
                    m_name.c_str(), m_type.c_str(), m_name.c_str(), m_name.c_str(), m_writeParcel.c_str());

            tmp.append(std::string(tt));
        }
        else {
            tmp.append("_data.");
            tmp.append(m_writeParcel);
            tmp.append("(");
            tmp.append(m_name);
            tmp.append(");\n");
        }

        return format(tmp, tab_size);
    }

protected:
    std::string m_name; // the name of args
    std::string m_type; // the value write in source file
    std::string m_localType;

    std::string m_readParcel;
    std::string m_writeParcel;

    bool m_array;
};

class ByteType : public BasicType
{
public:
    ByteType(std::string name, bool isArray = false)
        : BasicType(name, "char", isArray)
    {
        m_readParcel = std::string("readByte");
        m_writeParcel = std::string("writeByte");
    }

    static std::string name()
    {
        return "byte";
    }

    ~ByteType() {}

};

class ShortType : public BasicType
{
public:
    ShortType(std::string name, bool isArray = false)
        : BasicType(name, "int", isArray)
    {
        m_readParcel = std::string("readInt32");
        m_writeParcel = std::string("writeInt32");
    }

    static std::string name()
    {
        return "short";
    }

    ~ShortType() {}

};

class IntType : public BasicType
{
public:
    IntType(std::string name, bool isArray = false)
        : BasicType(name, "int", isArray)
    {
        m_readParcel = std::string("readInt32");
        m_writeParcel = std::string("writeInt32");
    }

    ~IntType() {}

    static std::string name()
    {
        return "int";
    }
};

class Int64Type : public BasicType
{
public:
    Int64Type(std::string name, bool isArray = false)
        : BasicType(name, "int64", isArray)
    {
        m_readParcel = std::string("readInt64");
        m_writeParcel = std::string("writeInt64");
    }

    ~Int64Type() {}

    static std::string name()
    {
        return "int64";
    }
};

class FloatType : public BasicType
{
public:
    FloatType(std::string name, bool isArray = false)
        : BasicType(name, "float", isArray)
    {
        m_readParcel = std::string("readFloat");
        m_writeParcel = std::string("writeFloat");
    }

    ~FloatType() {}

    static std::string name()
    {
        return "float";
    }
};

class BoolType : public BasicType
{
public:
    BoolType(std::string name, bool isArray = false)
        : BasicType(name, "bool", isArray)
    {
        m_readParcel = std::string("readInt32");
        m_writeParcel = std::string("writeInt32");
    }

    ~BoolType() {}

    static std::string name()
    {
        return "bool";
    }
};

class String8Type : public BasicType
{
public:
    String8Type(std::string name, bool isArray = false)
        : BasicType(name, "android::String8", isArray)
    {
        m_readParcel = "readString8";
        m_writeParcel = "writeString8";
    }

    ~String8Type() {}

    static std::string name()
    {
        return "string";
    }
};

class String16Type : public BasicType
{
public:
    String16Type(std::string name, bool isArray = false)
        : BasicType(name, "android::String16", isArray)
    {
        m_readParcel = "readString16";
        m_writeParcel = "writeString16";
    }

    ~String16Type() {}

    static std::string name()
    {
        return "string16";
    }
};

class UserType : public BasicType
{
public:
    UserType(std::string sign, std::string name, bool isArray = false)
        : BasicType(name, sign, isArray)
    {
        m_spName = std::string("android::sp<");
        m_spName.append(sign);
        m_spName.append(">");
        m_spName.append(" ");

        m_vecSpName = std::string("std::vector<");
        m_vecSpName.append(m_spName);
        m_vecSpName.append(">");
        m_vecSpName.append(" ");
    }

    ~UserType() {}

    static std::string name()
    {
        return "unknown";
    }

    virtual bool basicType()
    {
        return false;
    }

    /*
     * a(new User)
     */
    virtual std::string constructor()
    {
        if (m_array) {
            return BasicType::constructor();
        }
        else {
            std::string tmp(m_name);
            tmp.append("(new ");
            tmp.append(m_localType);
            tmp.append(")");
            return tmp;
        }
    }
    
    /*
     * const android::sp<User>& getuser() 
     * {
     *      return user;
     * }
     *
     **/
    virtual std::string getFunc(int tab_size = 0)
    {
        std::string tmp("const ");
        if (m_array)
            tmp.append(m_vecSpName);
        else
            tmp.append(m_spName);

        tmp.append("& get");
        tmp.append(upFirst(m_name));
        tmp.append("() { return ");
        tmp.append(m_name);
        tmp.append("; }\n");
        
        tmp.append("void set");
        tmp.append(upFirst(m_name));
        tmp.append("(");
        tmp.append("const ");
        if (m_array)
            tmp.append(m_vecSpName);
        else
            tmp.append(m_spName);
        tmp.append("& _");
        tmp.append(m_name);
        tmp.append(") {");
        tmp.append(m_name);
        tmp.append(" = _");
        tmp.append(m_name);
        tmp.append("; }\n\n");

        return format(tmp, tab_size);
    }

    /*
     * android::sp<User> a(new User);
     * std::vector<android::sp<User> > a();
     */
    virtual std::string declare(const char* v = NULL)
    {
        std::string tmp;
        if (m_array) {
            tmp.append(m_vecSpName);
            if (v) {
                tmp.append(v);
            }
            else {
                tmp.append(m_name);
            }
            tmp.append(";\n");
        }
        else
        {
            tmp.append(m_spName);
            if (v) {
                tmp.append(v);
            }
            else {
                tmp.append(m_name);
            }
            tmp.append("(new ");
            tmp.append(m_localType);
            tmp.append(");\n");
        }
        return tmp;
    }

    /*
     * android::sp<User> a
     * std::vector<android::sp<User> > a
     */
    virtual std::string define(int tab_size = 0)
    {
        std::string tmp;
        if (m_array)
            tmp.append(m_vecSpName);
        else
            tmp.append(m_spName);

        tmp.append(m_name);
        tmp.append(";");

        return format(tmp, tab_size);
    }

    /*
     * const android::sp<User>& a
     * const std::vector<android::sp<User> >& a
     */
    virtual std::string declparam()
    {
        std::string tmp;
        tmp.append("const ");
        if (m_array) {
            tmp.append(m_vecSpName);
        }
        else {
            tmp.append(m_spName);
        }
        tmp.append("& ");
        tmp.append(m_name);
        tmp.append(" ");

        return tmp;
    }

    /*
     * android::sp<User>& a
     * std::vector<android::sp<User> >& a
     */
    virtual std::string writeparam()
    {
        std::string tmp;
        if (m_array) {
            tmp.append(m_vecSpName);
        }
        else {
            tmp.append(m_spName);
        }
        tmp.append(m_name);
        tmp.append(" ");
        return tmp;
    }

    /*
     * a->readFromParcel(data);
     * {
     * int _len = data.readInt32();
     * for (int i = 0; i < len; i++) {
     *     android::sp<User> _tmp(new User);
     *     _tmp->readFromParcel(data);
     *     a.push_back(_tmp);
     * }
     * }
     */
    virtual std::string from(int tab_size, bool decl = true)
    {
        std::string tmp;
        if (decl)
            tmp.append(declare());

        if (m_array) {
            tmp.append("{\n");
            tmp.append("int _len = data.readInt32();\n");
            tmp.append("for (int i = 0; i < _len; i++) {\n");
            m_array = false;
            tmp.append(declare("_tmp"));
            m_array = true;
            tmp.append(" _tmp->readFromParcel(data);\n");
            tmp.append(m_name);
            tmp.append(".push_back(_tmp);\n}\n}\n");
        }
        else {
            tmp.append(m_name);
            tmp.append("->readFromParcel(data);\n");
        }

        return format(tmp, tab_size);
    }

    /*
         * a->writeToParcel(_data);
         * {
         * _data.writeInt32(a.length());
         * std::vector<android::sp<User> >::iterator it = a.begin();
         * for (; it != a.end(); it++) {
         *     (*it)->writeToParcel(_data);
         * }
         * }
         */
    virtual std::string to(int tab_size, bool decl = false)
    {
        std::string tmp;
        if (decl)
            tmp.append(declare());

        if (m_array) {
            char tt[1024];
            bzero(tt, sizeof tt);
            sprintf(tt, "{\n_data.writeInt32(%s.size());\n"\
                    "%s::const_iterator it = %s.begin();\n"\
                    "for (; it != %s.end(); it++) {\n"\
                    "(*it)->writeToParcel(_data);\n}\n}\n",
                    m_name.c_str(), m_vecSpName.c_str(), m_name.c_str(), m_name.c_str());

            tmp.append(std::string(tt));
        }
        else {
            tmp.append(m_name);
            tmp.append("->writeToParcel(_data);\n");
        }

        return format(tmp, tab_size);
    }

private:
    std::string m_spName;
    std::string m_vecSpName;

};


class BasicTypeFactory
{
public:
    static BasicType* create_type(const char* name, const char* type, bool isArray = false)
    {
        if (!ByteType::name().compare(type)) {
            return new ByteType(name, isArray);
        }
        else if (!ShortType::name().compare(type)) {
            return new ShortType(name, isArray);
        }
        else if (!IntType::name().compare(type)) {
            return new IntType(name, isArray);
        }
        else if (!Int64Type::name().compare(type)) {
            return new Int64Type(name, isArray);
        }
        else if (!FloatType::name().compare(type)) {
            return new FloatType(name, isArray);
        }
        else if (!BoolType::name().compare(type)) {
            return new BoolType(name, isArray);
        }
        else if (!String8Type::name().compare(type)) {
            return new String8Type(name, isArray);
        }
        else if (!String16Type::name().compare(type)) {
            return new String16Type(name, isArray);
        }
        else
        {
            return new UserType(type, name, isArray);
        }
    }
};


#endif
