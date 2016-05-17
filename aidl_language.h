#ifndef DEVICE_TOOLS_AIDL_AIDL_LANGUAGE_H
#define DEVICE_TOOLS_AIDL_AIDL_LANGUAGE_H


typedef enum {
    NO_EXTRA_TEXT = 0,
    SHORT_COMMENT,
    LONG_COMMENT,
    COPY_TEXT,
    WHITESPACE
} which_extra_text;

typedef struct extra_text_type {
    unsigned lineno;
    which_extra_text which;
    char* data; 
    unsigned len;
    struct extra_text_type* next;
} extra_text_type;

typedef struct buffer_type {
    unsigned lineno;
    unsigned token;
    char *data;
    extra_text_type* extra;
} buffer_type;

typedef struct enum_list
{
    buffer_type comma_token;
    buffer_type buffer;
    struct enum_list* next;
};

typedef struct type_type {
    buffer_type type;
    buffer_type array_token;
    int dimension;
} type_type;

typedef struct arg_type {
    buffer_type comma_token; // empty in the first one in the list
    buffer_type direction;
    type_type type;
    buffer_type name;
    struct arg_type *next;
} arg_type;

enum {
    METHOD_TYPE,
    COMMAND_TYPE,
    MULTICAST_TYPE
};

typedef struct interface_item_type {
    unsigned item_type;
    struct interface_item_type* next;
} interface_item_type;

typedef struct method_type {
    interface_item_type interface_item;
    type_type type;
    bool oneway;
    buffer_type oneway_token;
    buffer_type name;
    buffer_type open_paren_token;
    arg_type* args;
    buffer_type close_paren_token;
    // XXX missing comments/copy text here
    buffer_type semicolon_token;
    buffer_type* comments_token; // points into this structure, DO NOT DELETE
} method_type;

typedef struct command_type {
    interface_item_type interface_item;
    buffer_type name;
    buffer_type open_paren_token;
    arg_type* args;
    buffer_type close_paren_token;
    // XXX missing comments/copy text here
    buffer_type semicolon_token;
    buffer_type direction;
    buffer_type* comments_token; // points into this structure, DO NOT DELETE
} commmand_type;

typedef struct multicast_type {
    interface_item_type interface_item;
    buffer_type sign;
    buffer_type name;
    buffer_type domain;
    buffer_type open_paren_token;
    arg_type* args;
    buffer_type close_paren_token;
    // XXX missing comments/copy text here
    buffer_type semicolon_token;
    buffer_type* comments_token; // points into this structure, DO NOT DELETE
} multicast_type;

enum language_t {
	JAVA = 0,	
	CPP = 1
};

enum {
    USER_DATA_TYPE = 12,
    INTERFACE_TYPE_BINDER,
    ENUM_DATA_TYPE,
};

typedef struct document_item_type {
    unsigned item_type;
    struct document_item_type* next;
} document_item_type;

struct import_info {
    const char* from;
    const char* filename;
    buffer_type statement;
    const char* neededClass;
    document_item_type* doc;
    struct import_info* next;
};


// for user_data_type.flattening_methods
enum {
    PARCELABLE_DATA = 0x1,
    RPC_DATA = 0x2
};

typedef struct user_data_type {
    document_item_type document_item;
    buffer_type keyword_token; // only the first one
    char* package;
    buffer_type name;
    arg_type* args;
    buffer_type semicolon_token;
    int flattening_methods;
} user_data_type;

typedef struct enum_data_type {
    document_item_type document_item;
    buffer_type sign;
    buffer_type name;
    buffer_type open_paren_token;
    enum_list*  enumm_list;
    buffer_type close_paren_token;
    buffer_type semicolon_token;
    buffer_type* comments_token; // points into this structure, DO NOT DELETE
} enum_data_type;


typedef struct interface_type {
    document_item_type document_item;
    buffer_type interface_token;
    bool oneway;
    buffer_type oneway_token;
    char* package;
    buffer_type name;
    buffer_type open_brace_token;
    interface_item_type* interface_items;
    buffer_type close_brace_token;
    buffer_type* comments_token; // points into this structure, DO NOT DELETE
} interface_type;

typedef union lexer_type {
    buffer_type buffer;
    type_type type;
    arg_type *arg;
    method_type* method;
    multicast_type* multicast;
    command_type* command;
    enum_data_type* enum_item;
    enum_list* enumm_list;
    interface_item_type* interface_item;
    interface_type* interface_obj;
    user_data_type* user_data;
    document_item_type* document_item;
} lexer_type;


#define YYSTYPE lexer_type

#if __cplusplus
extern "C" {
#endif

int parse_aidl(char const *);

// strips off the leading whitespace, the "import" text
// also returns whether it's a local or system import
// we rely on the input matching the import regex from below
char* parse_import_statement(const char* text);

// in, out or inout
enum {
    IN_PARAMETER = 1,
    OUT_PARAMETER = 2,
    INOUT_PARAMETER = 3
};
int convert_direction(const char* direction);

// callbacks from within the parser
// these functions all take ownership of the strings
typedef struct ParserCallbacks {
    void (*document)(document_item_type* items);
    void (*import)(buffer_type* statement);
} ParserCallbacks;

extern ParserCallbacks* g_callbacks;

// true if there was an error parsing, false otherwise
extern int g_error;

// the name of the file we're currently parsing
extern char const* g_currentFilename;

// the package name for our current file
extern char const* g_currentPackage;

extern document_item_type* g_document;

typedef enum {
    STATEMENT_INSIDE_INTERFACE
} error_type;

void init_buffer_type(buffer_type* buf, int lineno);
void init_direction(buffer_type* buf, int lineno);


#if __cplusplus
}
#endif


#endif // DEVICE_TOOLS_AIDL_AIDL_LANGUAGE_H
