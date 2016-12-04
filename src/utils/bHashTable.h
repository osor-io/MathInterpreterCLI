#ifndef BDC_BHASHTABLE_H
#define BDC_BHASHTABLE_H

typedef enum {
    HASH_SUCCESS, HASH_ERROR
} returnType;


#define TABLESIZE 10009

typedef struct hashElement hashElement;

struct hashElement {
    char *key;
    void *data;
    hashElement *next;
};

typedef struct hashElement **hashTable;


int initHashTable(hashTable **table);

int deleteHastTable(hashTable **table,short variables);

unsigned int badHash(char *key);

hashElement *addElement(hashTable *table, char *key, void *data);

hashElement *getElement(hashTable *table, char *key);

int deleteElement(hashTable *table, char *key);

void printState(hashTable table);

void printData(hashTable table);

void printDataSorted(hashTable table, short vervose);

void printAllVariables(hashTable table);


#endif //BDC_BHASHTABLE_H
