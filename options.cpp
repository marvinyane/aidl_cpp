
#include "options.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
usage()
{
    fprintf(stderr,
            "usage: aidl OPTIONS INPUT \n"
            "\n"
            "OPTIONS:\n"
            "   -o<FOLDER> base output folder for generated files.\n"
            "\n"
            "INPUT:\n"
            "   An aidl interface file.\n"
            "\n"
            "OUTPUT:\n"
            "   The generated interface files.\n"
            "   If omitted and the -o option is not used, the input filename is used, with the .aidl extension changed to a .java extension.\n"
            "   If the -o option is used, the generated files will be placed in the base output folder, under their package folder\n"
           );
    return 1;
}

int
parse_options(int argc, const char* const* argv, Options *options)
{
    int i = 1;

    options->task = COMPILE_AIDL;
    options->failOnParcelable = false;
    options->virtualFunc = false;
    options->replierBase = false;

    // OPTIONS
    while (i < argc) {
        const char* s = argv[i];
        int len = strlen(s);
        if (s[0] == '-') {
            if (len > 1) {
               if (s[1] == 'o') {
                    if (len > 2) {
                        options->outputBaseFolder = s+2;
                    } else {
                        fprintf(stderr, "-o option (%d) requires a path.\n", i);
                        return usage();
                    }
                }
                else if (s[1] == 'v')
                {
                    options->virtualFunc = true;
                }
                else if (s[1] == 'b')
                {
                    options->replierBase = true;
                }
                else {
                    // s[1] is not known
                    fprintf(stderr, "unknown option (%d): %s\n", i, s);
                    return usage();
                }
            } else {
                // len <= 1
                fprintf(stderr, "unknown option (%d): %s\n", i, s);
                return usage();
            }
        } else {
            // s[0] != '-'
            break;
        }
        i++;
    }

    // INPUT
    if (i < argc) {
        options->inputFileName = argv[i];
        i++;
    } else {
        fprintf(stderr, "INPUT required\n");
        return usage();
    }

    // anything remaining?
    if (i != argc) {
        fprintf(stderr, "unknown option%s:", (i==argc-1?(const char*)"":(const char*)"s"));
        for (; i<argc-1; i++) {
            fprintf(stderr, " %s", argv[i]);
        }
        fprintf(stderr, "\n");
        return usage();
    }

    return 0;
}

