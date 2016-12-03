#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>
#include "symbolTable/symbolTable.h"
#include "readerSystem/readerSystem.h"
#include "errorManager/errorManager.h"

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
    short workAfterFile = 0, alreadySaidFile = 0;

    printf("\n");
    if (argc == 1) {
        printf("Starting with the default mode...\n");
    } else {

        while ((c = getopt(argc, argv, "l:i:f:")) != -1)
            switch (c) {
                case 'l':
                    if (alreadySaidFile) {
                        manageFatalError(ERR_FILE_ERROR,
                                         "You cant load a file (-l) after including one for interpretation with (-f)");
                    }
                    filename = optarg;
                    workAfterFile = 1;
                    alreadySaidFile = 1;
                    break;
                case 'i':
                    includedPaths[includedFileIndex++] = optarg;
                    break;
                case 'f':
                    if (alreadySaidFile) {
                        manageFatalError(ERR_FILE_ERROR, "You cant include a file (-f) after loading one (-l)");
                    }
                    filename = optarg;
                    alreadySaidFile = 1;
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
    initSymbolTable(&st);
    global_st = st;

    printf("\n\nWelcome to WolframBeta 0.1: \n\n");

    readerSystem *rs = NULL;
    if (filename != NULL) {                     //WORKING IN FILE MODE
        //Init the reader system
        rs = NULL;
        initReaderSystem(&rs, filename);
        global_rs = rs;
        yyin = rs->file;

        yyparse();

        if (workAfterFile) {
            yyrestart(stdin);
            yyparse();
        }

    } else {
        yyparse();
    }

    yylex_destroy();


    //And we delete everything before ending the program
    if (!st)
        deleteSymbolTable(&st);
    if (!rs)
        deleteReaderSystem(&rs);


    return EXIT_SUCCESS;

}
