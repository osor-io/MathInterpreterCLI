#include <stdio.h>
#include "defineParser.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*
void parseReservedWords(symbolTable **oSymbolTable, char *pathToDefineFile) {

    FILE *file = fopen(pathToDefineFile, "r");       //Open the file


    if (file == NULL) {
        char buffer[256];
        sprintf(buffer, "Error opening file: %s\n", pathToDefineFile);
        manageFatalError(ERR_FILE_ERROR, buffer);
    }


    char line[256];                                 //Save space for a line, should not be longer than 256

    while (fgets(line, sizeof(line), file)) {
        char defBuf[64];
        int LexCompBuf;
        char resWordBuf[64];
        sscanf(line, "#define %[^ ] %d //## %[^ \n]\n", defBuf, &LexCompBuf, resWordBuf);


        char *key = (char *) malloc((strlen(resWordBuf) + 1) * sizeof(char));
        unsigned int i = 0;
        for (i = 0; i < strlen(resWordBuf); i++) {
            key[i] = resWordBuf[i];
        }
        key[strlen(resWordBuf)] = '\0';

        symbolData *msymbolData = (symbolData *) malloc(sizeof(symbolData));

        //msymbolData->lexicalComponent = LexCompBuf;

        addElement(((*oSymbolTable)->reserved), key, (void *) msymbolData);
    }sin
    fclose(file);
}*/



struct init_fncts {
    char *fname;

    double (*fnct)(double);
};

struct init_fncts arith_fncts[]
        = {
                "acos", acos,
                "asin", asin,
                "atan", atan,
                "ceil", ceil,
                "cos", cos,
                "cosh", cosh,
                "exp", exp,
                "fabs", fabs,
                "floor", floor,
                "log", log,
                "log10", log10,
                "sin", sin,
                "sinh", sinh,
                "sqrt", sqrt,
                "tan", tan,
                "tanh", tanh,
                "erf", erf,
                "erfc", erfc,
                "j0", j0,
                "j1", j1,
                "lgamma", lgamma,
                "y0", y0,
                "y1", y1,
                "acosh", acosh,
                "asinh", asinh,
                "atanh", atanh,
                "cbrt", cbrt,
                "expm1", expm1,
                "logb", logb,
                "rint", rint,
                0, 0
        };

struct init_constants {
    char *name;
    double value;
};

struct init_constants arith_constants[] = {
        "e", M_E,
        "pi", M_PI,
        0, 0
};

void parseConstants(symbolTable **oSymbolTable) {

    char *key = NULL;
    unsigned short index = 0;
    int i;

    for (i = 0; arith_constants[i].name != 0; i++) {

        symbolData *msymbolData = (symbolData *) malloc(sizeof(symbolData));
        variableContent *mVariableContent = (variableContent *) malloc(sizeof(variableContent));
        key = (char *) malloc(sizeof(char) * 10);
        mVariableContent->value.columns = 1;
        mVariableContent->value.rows = 1;
        mVariableContent->value.defAsMatrix = 0;
        mVariableContent->value.values = malloc(sizeof(double *));
        mVariableContent->value.values[0] = malloc(sizeof(double));
        mVariableContent->value.values[0][0] = (arith_constants[i].value);
        mVariableContent->defined = 1;
        mVariableContent->name = (char *) malloc(sizeof(char) * 10);

        strcpy(key, arith_constants[i].name);
        strcpy(mVariableContent->name, key);
        msymbolData->type = TYPE_CONSTANT;
        msymbolData->content = mVariableContent;
        addElement(((*oSymbolTable)->identifiers), key, (void *) msymbolData);
    }

}

void parseFunctions(symbolTable **oSymbolTable) {
    char *key = NULL;
    unsigned short index = 0;
    int i;
    for (i = 0; arith_fncts[i].fname != 0; i++) {

        symbolData *msymbolData = (symbolData *) malloc(sizeof(symbolData));
        functionContent *mfunctionContent = (functionContent *) malloc(sizeof(functionContent));
        key = (char *) malloc(sizeof(char) * 10);
        mfunctionContent->funcPointer = (arith_fncts[i].fnct);
        msymbolData->type = TYPE_FUNCTION;
        msymbolData->content = mfunctionContent;
        strcpy(key, arith_fncts[i].fname);
        addElement(((*oSymbolTable)->reserved), key, (void *) msymbolData);
    }


    printReservedWords(*oSymbolTable);
}
