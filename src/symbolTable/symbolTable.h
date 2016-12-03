#include "../utils/bHashTable.h"

#ifndef BDC_SYMBOLTABLE_H
#define BDC_SYMBOLTABLE_H


/*
 *
 * An easy change would be to have an array of hashTables for each different block or level if we had to take blocks or levels into account.
 *
 * This would mean that we would be using quite a bit more memory but the deletion of a whole table would be easier when we close a block or level.
 *
 * Since we don't have to work with blocks or levels yet the identifiers table will be implemented as a single hash table, which could work good also if we
 * needed blocks or levels.
 *
 * */
typedef struct {
    hashTable *reserved;
    hashTable *identifiers;
} symbolTable;

typedef struct {            //More data could be added here, this will be the void *data inserted into the hast tables
    int type;
    void * content;
} symbolData;

typedef struct {
  double (*funcPointer)(double);
} functionContent;

typedef struct {
    double** values;
    short rows;
    short columns;
    short defAsMatrix;
} variableValue;

typedef struct {
  variableValue value;
  unsigned short defined;
  char* name;
} variableContent;


typedef enum {
    TYPE_VARIABLE,
    TYPE_FUNCTION
} symbolType;


void initSymbolTable(symbolTable **oSymbolTable);

void deleteSymbolTable(symbolTable **oSymbolTable);

//We could insert here more functions in case we need them in order to update the block, delete elements or something like that

symbolData *searchLex(symbolTable *oSymbolTable, char *lex);

int addLex(symbolTable **oSymbolTable, char *lex, symbolData *data);

void printSymbolTable(symbolTable *oSymbolTable);

void printReservedWords(symbolTable *oSymbolTable);

void printVariables(symbolTable *oSymbolTable);

#endif //BDC_SYMBOLTABLE_H
