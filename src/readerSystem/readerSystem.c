#include "readerSystem.h"
#include "../errorManager/errorManager.h"
#include <stdlib.h>
#include <sys/stat.h>


extern readerSystem *global_rs;


/**
 * Opens the file and reserves all the memory needed
 *
 * It also init the variables of the rs to the correct ones.
 *
 * */
void initReaderSystem(readerSystem **rs, char *filename) {
    *rs = (readerSystem *) malloc(sizeof(readerSystem));//Reserve size for the struct that defines the reader system
    global_rs = *rs;                                    //Update the global pointer for the error manager

    (*rs)->file = fopen(filename, "r");                 //We open the file itself
    if ((*rs)->file == NULL) {                          //We check if we have the file opened.
        char buffer[256];
        sprintf(buffer, "Error opening file: %s\n", filename);
        manageFatalError(ERR_FILE_ERROR, buffer);
    }

    return;
}


/**
 * Frees the memory used for the reader system
 *
 * */
void deleteReaderSystem(readerSystem **rs) {

    if ((*rs)->file != NULL)
        if (fclose((*rs)->file) != 0) {
            char buffer[256];
            sprintf(buffer, "Error closing source file\n");
            manageNonFatalError(ERR_FILE_ERROR, buffer);
        }
    free(*rs);
    return;
}
