#include <stdio.h>
#include "defineParser.h"
#include "../errorManager/errorManager.h"
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
    }
    fclose(file);
}*/

// function type
typedef double (*OneArgFunctionCallback)(double);

OneArgFunctionCallback functions[] = {
        &acos,
        &asin,
        &atan,
        &ceil,
        &cos,
        &cosh,
        &exp,
        &fabs,
        &floor,
        &log,
        &log10,
        &sin,
        &sinh,
        &sqrt,
        &tan,
        &tanh,
        &erf,
        &erfc,
        &j0,
        &j1,
        &lgamma,
        &y0,
        &y1,
        &acosh,
        &asinh,
        &atanh,
        &cbrt,
        &expm1,
        &logb,
        &rint,
        NULL
};

void getNameOf(unsigned short index, char *name) {


    switch (index) {

        case (0):
            strcpy(name, "acos");
            break;
        case (1):
            strcpy(name, "asin");
            break;
        case (2):
            strcpy(name, "atan");
            break;
        case (3):
            strcpy(name, "ceil");
            break;
        case (4):
            strcpy(name, "cos");
            break;
        case (5):
            strcpy(name, "cosh");
            break;
        case (6):
            strcpy(name, "exp");
            break;
        case (7):
            strcpy(name, "fabs");
            break;
        case (8):
            strcpy(name, "floor");
            break;
        case (9):
            strcpy(name, "log");
            break;
        case (10):
            strcpy(name, "log10");
            break;
        case (11):
            strcpy(name, "sin");
            break;
        case (12):
            strcpy(name, "sinh");
            break;
        case (13):
            strcpy(name, "sqrt");
            break;
        case (14):
            strcpy(name, "tan");
            break;
        case (15):
            strcpy(name, "tanh");
            break;
        case (16):
            strcpy(name, "erf");
            break;
        case (17):
            strcpy(name, "erfc");
            break;
        case (18):
            strcpy(name, "j0");
            break;
        case (19):
            strcpy(name, "j1");
            break;
        case (20):
            strcpy(name, "lgamma");
            break;
        case (21):
            strcpy(name, "y0");
            break;
        case (22):
            strcpy(name, "y1");
            break;
        case (23):
            strcpy(name, "acosh");
            break;
        case (24):
            strcpy(name, "asinh");
            break;
        case (25):
            strcpy(name, "atanh");
            break;
        case (26):
            strcpy(name, "cbrt");
            break;
        case (27):
            strcpy(name, "expm1");
            break;
        case (28):
            strcpy(name, "logb");
            break;
        case (29):
            strcpy(name, "rint");
            break;
        default:
            manageFatalError(ERR_CANT_PARSE_FUNCTION, "Cannot find a name for a function while parsing.");
            break;
    }

    return;
}

void parseFunctions(symbolTable **oSymbolTable) {
    char *key = NULL;
    unsigned short index = 0;
    while (functions[index]) {
        symbolData *msymbolData = (symbolData *) malloc(sizeof(symbolData));
        functionContent *mfunctionContent = (functionContent *) malloc(sizeof(functionContent));
        mfunctionContent->funcPointer = functions[index];
        msymbolData->type = TYPE_FUNCTION;
        msymbolData->content = mfunctionContent;
        key = (char *) malloc(sizeof(char) * 10);
        getNameOf(index, key);
        addElement(((*oSymbolTable)->reserved), key, (void *) msymbolData);
        index++;
    }
    printReservedWords(*oSymbolTable);
}
