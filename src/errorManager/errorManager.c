#include <stdlib.h>
#include <stdio.h>
#include "errorManager.h"
#include "../utils/colours.h"
#include "../symbolTable/symbolTable.h"
#include "../readerSystem/readerSystem.h"

extern symbolTable *global_st;
extern readerSystem *global_rs;

/**
 * We print the apropriate message for each error code.
 *
 * */
void printMessageFor(int code) {
    switch (code) {
        case ERR_UNEXPECTED_EOF:
            printf("Unexpected End of File");
            break;
        case ERR_BAD_OPERATOR:
            printf("Malformed Operator");
            break;
        case ERR_FILE_ERROR:
            printf("Error managing external file");
            break;
        case ERR_BAD_BINARY:
            printf("Malformed binary number");
            break;
        case ERR_BAD_SCI_NO:
            printf("Malformed number with scientific notation");
            break;
        case ERR_LEXEME_TOO_LARGE:
            printf("Lexeme size unsupported");
            break;
        case ERR_JUMP_LINE_IN_LITERAL:
            printf("Found a jump line inside a literal");
            break;
        case ERR_SCAPE_CHAR:
            printf("Unsupported scape character");
            break;
        case ERR_CANT_PARSE_FUNCTION:
            printf("Function not supported for parsing");
            break;
        case ERR_BISON:
            printf("Bison detected an error");
            break;
        default:
            printf("No message for that code.");
            break;
    };
}

/**
 * We manage a fatal error showing the line and position given to us.
 *
 * It deletes and frees all memory currently used by the main modules of the program.
 *
 * */
void manageFatalErrorWithLine(int code, char *message, int line, int position) {

    printf(RED "ERROR CODE [%d]: ", code);              //Print the error code
    printMessageFor(code);                              //Print the message associated
    printf("\n\t%s\n\thappened at line %d, in position %d\n\n"RESET, message, line, position);   //And the line and position that had the error


    /*
     * In all the error manager functions we try to delete the core parts of the compiler if
     * they are initialized in order to free all memory used.
     * */

    if (global_st != NULL)
        deleteSymbolTable(&global_st);
    if (global_rs != NULL)
        deleteReaderSystem(&global_rs);


    exit(EXIT_FAILURE);
}


/**
 * We manage a fatal error without showing the line and position given to us.
 *
 * It deletes and frees all memory currently used by the main modules of the program.
 *
 * */
void manageFatalError(int code, char *message) {

    printf(RED"ERROR CODE [%d]: ", code);
    printMessageFor(code);
    printf("\n\t%s\n\n"RESET, message);


    if (global_st != NULL)
        deleteSymbolTable(&global_st);
    if (global_rs != NULL)
        deleteReaderSystem(&global_rs);


    exit(EXIT_FAILURE);
}


/**
 * We manage a non fatal error showing the line and position given to us.
 *
 * This allows the program to go on.
 * */
void manageNonFatalErrorWithLine(int code, char *message, int line, int position) {

    printf(RED"ERROR CODE [%d]: ", code);
    printMessageFor(code);
    printf("\n\t%s\n\thappened at line %d, in position %d\n\n"RESET, message, line, position);

    return;
}


/**
 * We manage a non fatal error without showing the line and position given to us.
 *
 * This allows the program to go on.
 * */
void manageNonFatalError(int code, char *message) {

    printf(RED"ERROR CODE [%d]: ", code);
    printMessageFor(code);
    printf("\n\t%s\n\n"RESET, message);

    return;

}
