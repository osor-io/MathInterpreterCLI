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


int main(int argc, char **argv) {

    char *filename = NULL;
    int c;
    short alreadySaidFile = 0;

    printf("\n");
    if (argc == 1) {
        printf("Starting with the default mode...\n");
    } else {

        while ((c = getopt(argc, argv, "l:")) != -1)
            switch (c) {
                case 'l':
                    if (alreadySaidFile) {
                        manageFatalError(ERR_FILE_ERROR, "You cant include more than one file (-l)");
                    }
                    filename = optarg;
                    alreadySaidFile = 1;
                    break;
                case '?':
                    if (optopt == 'l')
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
        printf("Input file selected: %s\n", filename);
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

    } else {
        rs=NULL;
        yyparse();
    }


    yylex_destroy();


    //And we delete everything before ending the program
    if (st) {
        deleteSymbolTable(&st);
    }
    if (rs) {
        deleteReaderSystem(&rs);
    }

    return EXIT_SUCCESS;

}
