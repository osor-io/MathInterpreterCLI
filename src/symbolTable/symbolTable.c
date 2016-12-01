#include <stdlib.h>
#include <stdio.h>
#include "symbolTable.h"
#include "../utils/defineParser.h"
#include "../utils/colours.h"

extern symbolTable *global_st;

/**
 * Initializes the symbol table and reserves memory for all its data
 * including the hash tables
 *
 * */
void initSymbolTable(symbolTable **oSymbolTable, char *pathToDefineFile) {
    *oSymbolTable = (symbolTable *) malloc(
            sizeof(symbolTable));                                   //We reserve memory for the struct of the symbol table
    global_st = *oSymbolTable;                                      //Update the global pointer for the error manager
    initHashTable(&((*oSymbolTable)->identifiers));                 //And for both hash tables we use
    initHashTable(&((*oSymbolTable)->reserved));

    parseReservedWords(oSymbolTable, pathToDefineFile);             //We parse the reserved words from a file with the parser.

}

/**
 * Deletes the hash tables and the symbol table itself.
 *
 * */
void deleteSymbolTable(symbolTable **oSymbolTable) {
    deleteHastTable(&((*oSymbolTable)->identifiers));               //First we delete the hash tables
    deleteHastTable(&((*oSymbolTable)->reserved));
    free(*oSymbolTable);                                            //And then the struct of the symbol table itself
}

/**
 * Searches for a lexeme in both hash tables.
 *
 * */
symbolData *searchLex(symbolTable *oSymbolTable, char *lex) {
    hashElement *mElement = getElement((oSymbolTable->reserved), lex);  //We look first in the reserved words table
    if (mElement == NULL) {                                             //If the lexeme is not a reserved word
        mElement = getElement((oSymbolTable->identifiers), lex);        //Then we look in the identifiers table

    }
    if (mElement == NULL) return NULL;
    return (symbolData *) mElement->data;                               //And return the result which can be NULL
}

/**
 * Ads a lexeme to the identifiers table.
 *
 * */
int addLex(symbolTable **oSymbolTable, char *lex, symbolData *data) {                   //This adds a lexeme to the table of identifiers
    return (addElement(((*oSymbolTable)->identifiers), lex, (void *) data) != NULL);    //We add the lexeme to the identifiers table
}

/**
 * Prints the state and data of both hash tables in a given moment
 *
 * */
void printSymbolTable(symbolTable *oSymbolTable) {
    printf("\n\n----------------PRINTING STATE AND DATA OF THE RESERVED WORDS TABLE----------------\n\n");
    printState(*oSymbolTable->reserved);
    printDataSorted(*oSymbolTable->reserved,1);

    printf("\n\n----------------PRINTING STATE AND DATA OF THE IDENTIFIERS TABLE----------------\n\n");
    printState(*oSymbolTable->identifiers);
    printDataSorted(*oSymbolTable->identifiers,1);
}

void printReservedWords(symbolTable *oSymbolTable){
    printf(GRN "FUNCTIONS CURRENTLY SUPPORTED:\n" RESET);
    printDataSorted(*oSymbolTable->reserved,0);

}

void printVariables(symbolTable *oSymbolTable){
    printf(GRN "\n\nVARIABLES CURRENTLY DEFINED:\n\n" RESET);
    printDataSorted(*oSymbolTable->identifiers,0);
}