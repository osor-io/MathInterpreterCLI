#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include "symbolTable/symbolTable.h"
#include "readerSystem/readerSystem.h"

symbolTable *global_st = NULL;
readerSystem *global_rs = NULL;

#include "./Flex&Bison/mainBison.tab.c"
#include "./Flex&Bison/lex.yy.c"

#define MAX_INCLUDED_FILES 20

int main(int argc, char **argv) {

    char *filename = NULL;
    char *ourPathToDefine = "./resources/RESERVED_WORDS.h";
    char *includedPaths[MAX_INCLUDED_FILES];
    int c, includedFileIndex = 0;

    printf("\n");
    if (argc == 1) {
        printf("Starting with the default mode...\n");
    } else {

        while ((c = getopt(argc, argv, "i:f:")) != -1)
            switch (c) {
                case 'i':
                    includedPaths[includedFileIndex++] = optarg;
                    break;
                case 'f':
                    filename = optarg;
                    break;
                case '?':
                    if (optopt == 'i' || optopt == 'f')
                        fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                    else if (isprint(optopt))
                        fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                    else
                        fprintf(stderr,
                                "Unknown option character `\\x%x'.\n",
                                optopt);
                    return 1;
                default:
                    abort();
            }

        includedPaths[includedFileIndex] = NULL;
        includedFileIndex = 0;

        printf("Input file selected: %s\n", filename);
        while (includedPaths[includedFileIndex] != NULL) {
            printf("Included file: %s\n", includedPaths[includedFileIndex++]);
        }

    }


    //Init the symbol table
    symbolTable *st = NULL;
    initSymbolTable(&st, ourPathToDefine);
    global_st = st;

    return EXIT_SUCCESS;


    //Init the reader system
    readerSystem *rs = NULL;
    initReaderSystem(&rs, filename);
    global_rs = rs;





    return EXIT_SUCCESS;
}


