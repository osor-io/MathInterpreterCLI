#ifndef BDC_READERSYSTEM_H
#define BDC_READERSYSTEM_H

#include <stdio.h>

typedef struct {
    FILE *file;
} readerSystem;


void initReaderSystem(readerSystem **rs, char *filename);

void deleteReaderSystem(readerSystem **rs);


#endif //BDC_READERSYSTEM_H
