
#include "aidl_language.h"
#include "options.h"
#include "generate_cpp.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/param.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

#ifdef HAVE_MS_C_RUNTIME
#include <io.h>
#include <sys/stat.h>
#endif

#ifndef O_BINARY
#  define O_BINARY  0
#endif

using namespace std;
static int generate_cpp_files = 1;

// ==========================================================
int
convert_direction(const char* direction)
{
    if (direction == NULL) {
        return IN_PARAMETER;
    }
    if (0 == strcmp(direction, "in")) {
        return IN_PARAMETER;
    }
    if (0 == strcmp(direction, "out")) {
        return OUT_PARAMETER;
    }
    return INOUT_PARAMETER;
}

// ==========================================================

document_item_type* g_document = NULL;

// ==========================================================
static int
exactly_one_interface(const char* filename, const document_item_type* items)
{
    if (items == NULL) {
        fprintf(stderr, "%s: file does not contain any interfaces\n",
                            filename);
        return 1;
    }

    document_item_type* item = (document_item_type*)items;
    document_item_type* finded = NULL;
    while (item) {
        if (item->item_type == INTERFACE_TYPE_BINDER) {
            if (finded != NULL) {
                fprintf(stderr, "%s: interface has existed\n",
                                    filename);
                return 1;
            }

            finded = item;
        }

        item = item->next;
    }

    return 0;
}

void dump_interface()
{
    document_item_type* _item = g_document;
    while (_item) {
        if (_item->item_type == INTERFACE_TYPE_BINDER) {
            interface_type* item = (interface_type*)_item;
            printf("interface item %s\n", item->name.data);

        }
        else if (_item->item_type == USER_DATA_TYPE) {
            user_data_type* item = (user_data_type*)_item;
            printf("user data type %s\n", item->name.data);
        }
        else {
            printf("unknown item type %d\n", _item->item_type);
        }

        _item = _item->next;
    }
}


// ==========================================================
static int
compile_aidl(Options& options)
{
    int err = 0, N;

    err = parse_aidl(options.inputFileName.c_str());
    document_item_type* mainDoc = g_document;

    if (err != 0 || mainDoc == NULL) {
        //fprintf(stderr, "aidl: parsing failed, stopping.\n");
        return 1;
    }

    err |= exactly_one_interface(options.inputFileName.c_str(), mainDoc);

    if (err != 0) {
        return 1;
    }

    err = generate_cpp(options.outputBaseFolder, options.inputFileName.c_str(), mainDoc, options.virtualFunc, options.replierBase);

    return err;
}

// ==========================================================
int
main(int argc, const char **argv)
{
    Options options;
    int result = parse_options(argc, argv, &options);
    if (result) {
        return result;
    }

    switch (options.task)
    {
        case COMPILE_AIDL:
            return compile_aidl(options);
    }
    fprintf(stderr, "aidl: internal error\n");
    return 1;
}
