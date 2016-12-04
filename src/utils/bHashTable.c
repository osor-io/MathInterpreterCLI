#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bHashTable.h"
#include "../utils/colours.h"

//ADHOC: This is unique to this project, could be deleted if needed.
#include "../symbolTable/symbolTable.h"

//---------------------HASH FUNCTION-------------------------
#define FNV1_32_INIT ((u_int32_t)0x811c9dc5)


/**
 * Hash function known as FNV-1A
 *
 * */
u_int32_t fnv_32a_str(char *str, u_int32_t hval) {      //This is the hash function
    unsigned char *s = (unsigned char *) str;           //We get the string as unsigned chars for the algorithm
    while (*s != '\0') {
        hval ^= (u_int32_t) *s++;                       //XOR the hash with the current octet (a char is an octet)
        //We multiply by the 32 bit FNV magic prime mod 2^32
        //Explanation of this in: http://isthe.com/chongo/tech/comp/fnv/
        hval += (hval << 1) + (hval << 4) + (hval << 7) + (hval << 8) + (hval << 24);
        //This above is basically a prime number with the necessary number of bits (32 in this case)
    }
    return hval;
}

/**
 * Function that just acts as an interface for the hash function.
 *
 * */
unsigned int
badHash(char *key) {                                    //This controls the current hash value used by the hash function and makes the call to it
    return (fnv_32a_str(key, FNV1_32_INIT)) % TABLESIZE;
}
//-----------------------------------------------------------





//--------------------TABLE LOGIC----------------------------
/**
 * The key does not gets copied since in this implementation we manage the deletion of the
 * keys but not the allocation of its memory
 *
 * The data itself is also not copied since this could come at a high cost and we
 * assume that we are not deleting the data we need since this hash table will be used just to
 * locate the data fast.
 *
 * Another NOTE: We are using strcmp to compare lexems, we have tested our own implementation of strcmp but
 * it is not nearly as fast as the original strcmp because compilers do a ton of smart optimizations to functions like this.
 *
 * */

/**
 * Reserves memory for the whole table
 * and sets its elements to NULL
 *
 * */
int initHashTable(hashTable **table) {
    *table = (hashTable *) malloc(sizeof(hashTable *));                 //Reserve memory for the pointer to our table
    **table = (hashTable) malloc(
            sizeof(hashElement *) *
            TABLESIZE);                         //Reserve memory for the array of pointers to the elements

    int i = 0;
    for (i = 0; i < TABLESIZE; ++i) {
        (**table)[i] = NULL;
    }

    return HASH_SUCCESS;
}

/**
 * Deletes all elements from the hash table (key and data)
 * To then delete the table itself
 *
 * */
int deleteHastTable(hashTable **table, short variables) {

    if (table == NULL || *table == NULL || **table == NULL)
        return HASH_ERROR;                              //If the pointer to the table, the table, or the elements are NULL then we cannot delete.

    int i;
    hashElement *currentElement, *elementToDelete;

    for (i = 0; i < TABLESIZE; i++) {                   //We look in all the elements in the table
        if ((**table)[i] != NULL) {                     //If the element is not null
            elementToDelete = (**table)[i];             //We need to delete it
            currentElement = elementToDelete->next;     //And we save a reference to the next one in the list to delete
            if (elementToDelete->data != NULL) {

                if (variables) {    //DELETING A VARIABLE
                    //ADHOC:
                    variableContent *vc = (((symbolData *) (elementToDelete->data))->content);
                    free(vc->name);
                    int r;
                    for (r = 0; r < vc->value.rows; r++) {
                        free(vc->value.values[r]);
                    }
                    free(vc->value.values);
                    free(vc);
                } else {
                    functionContent *fc = (((symbolData *) (elementToDelete->data))->content);
                    free(fc);
                }

                free(elementToDelete->data);            //We have chosen to delete the elements data when we delete the element itself if it's not set to NULL
            }
            free(elementToDelete->key);
            free(elementToDelete);
            while (currentElement !=
                   NULL) {                              //We iterate through all the elements in the list for that position to delete them all
                elementToDelete = currentElement;
                currentElement = elementToDelete->next;
                if (elementToDelete->data != NULL) {

                    if (variables) {
                        //ADHOC:
                        variableContent *vc = (((symbolData *) (elementToDelete->data))->content);
                        free(vc->name);
                        int r;
                        for (r = 0; r < vc->value.rows; r++) {
                            free(vc->value.values[r]);
                        }
                        free(vc->value.values);
                        free(vc);
                    } else {
                        functionContent *fc = (((symbolData *) (elementToDelete->data))->content);
                        free(fc);
                    }

                    free(elementToDelete->data);            //We have chosen to delete the elements data when we delete the element itself if it's not set to NULL
                }
                free(elementToDelete->key);
                free(elementToDelete);
            }
        }
    }
    free(**table);                                      //We free the array of pointers to the elements
    free(*table);                                       //And the pointer to the table

    return HASH_SUCCESS;
}

/**
 * Adds a new element to the hash table
 * */
hashElement *addElement(hashTable *table, char *key, void *data) {

    if (table == NULL || *table == NULL)
        return NULL;                                            //If the the table, or its elements are NULL then we cannot insert anything.


    hashElement *newElement, *oldElement;
    newElement = (hashElement *) malloc(sizeof(hashElement));   //Locate memory for the new element to be added

    newElement->data = NULL;

    //Uncomment the next line if you want to copy the key instead of just using the one that is given.
    //#define HASHTABLE_COPYKEY


#ifdef HASHTABLE_COPYKEY
    int length = (int)strlen(key) + 1;

    int i;

    newElement->key = (char *) malloc(length*sizeof(char));

    for (i = 0; i < length; i++) {                              //We copy the key into our struct
        newElement->key[i] = key[i];
    }
#endif

    newElement->key = key;

    newElement->data = data;                                    //We assign the data of the element into the struct


    unsigned int hashNumber = badHash(
            key);                     //We get the position in the table with the hash function

    if ((*table)[hashNumber] == NULL) {                         //If there is no element in the position
        (*table)[hashNumber] = newElement;                      //We put the element there
        newElement->next = NULL;                                //And set the next element to null
    } else {                                                    //If there is something in there
        //We insert at the beginning of the list
        oldElement = (*table)[hashNumber];
        (*table)[hashNumber] = newElement;                      //The first element is now the new element
        newElement->next = oldElement;                          //And the next in the list is the old first element
    }
    return newElement;

}

/**
 * We ge the element corresponding to a given key
 * Returns NULL if it does not exist on the table.
 *
 * */
hashElement *getElement(hashTable *table, char *key) {

    if (table == NULL || *table == NULL)
        return NULL;                                        //If the the table, or its elements are NULL then we cannot get any element

    hashElement *currentElement;
    unsigned int hashNumber = badHash(key);                 //We get the position of the element

    if ((*table)[hashNumber] == NULL) return NULL;          //If there is no element then we return NULL

    if (strcmp((*table)[hashNumber]->key, key) == 0) {      //If there is an element and the key is the same
        return (*table)[hashNumber];                        //We return the element
    } else {                                                //If the key is not the same we have to look for it
        currentElement = (*table)[hashNumber];
        while (currentElement->next != NULL) {              //While there is elements in the list
            currentElement = currentElement->next;
            if (strcmp(currentElement->key, key) == 0) {    //We search for out key
                return currentElement;                      //If we find it we return the element
            }
        }
        return NULL;                                        //If not we return NULL
    }
}

/**
 * Deletes an element in the hash table
 * freeing its data and key.
 *
 * Unused at the moment.
 *
 * */
int deleteElement(hashTable *table, char *key) {

    if (table == NULL || *table == NULL)
        return HASH_SUCCESS;                                //If the the table, or its elements are NULL then we cannot delete any element

    hashElement *currentElement;
    unsigned int hashNumber = badHash(key);

    if (table[hashNumber] == NULL) return HASH_ERROR;       //We cannot delete an element that is not in the table

    if (strcmp((*table)[hashNumber]->key, key) == 0) {      //If we find the element in the first position
        currentElement = (*table)[hashNumber];
        (*table)[hashNumber] = currentElement->next;        //Its child will be now in the first position
        if (currentElement->data != NULL)
            free(currentElement->data);                     //We have chosen to delete the elements data when we delete the element itself if it's not set to NULL
        free(currentElement->key);
        free(currentElement);                               //And we delete the element
        return HASH_SUCCESS;
    } else {                                                //If the element seems to be in the list
        hashElement *parentElement = (*table)[hashNumber];     //The parent element is the first one in the list
        currentElement = parentElement->next;               //And the current element is its child
        while (currentElement != NULL) {                    //While we are not in the last element
            if (strcmp(currentElement->key, key) == 0) {    //If we have found the element
                parentElement->next = currentElement->next; //The parent's child will now be the son's child
                if (currentElement->data != NULL)
                    free(currentElement->data);             //We have chosen to delete the elements data when we delete the element itself if it's not set to NULL
                free(currentElement->key);
                free(currentElement);                       //And we delete the element
                return HASH_SUCCESS;
            }                                               //if we have not found the element in this iteration
            parentElement = currentElement;                 //The parent now is the child of the old parent (current)
            currentElement = currentElement->next;          //The new current element is the son of the current element
        }
        return HASH_ERROR;                                  //If we can't find the element at all in the list then we cant delete it
    }
}

/**
 * This is just a debug function to show the status of the table
 *
 * We show data like the max length of a list, the total elements inserted, the positions with something in them
 * and the average size of the lists in the table.
 *
 * */
void printState(hashTable table) {

    if (table == NULL)
        return;                                        //If the the table is NULL then we cannot show the status it.

    int maxLength, totalElements, usedSlots, nodesInCurList, i;
    double average;
    hashElement *currentElement;

    maxLength = 0;
    totalElements = 0;
    usedSlots = 0;
    average = 0.0f;

    printf("\n\nPRINTING TABLE STATUS:\n\n");

    for (i = 0; i < TABLESIZE; i++) {
        if (table[i] != NULL) {

            usedSlots++;
            nodesInCurList = 0;
            currentElement = table[i];
            while (currentElement != NULL) {
                nodesInCurList++;
                currentElement = currentElement->next;
            }
            totalElements += nodesInCurList;
            if (nodesInCurList > maxLength) {
                maxLength = nodesInCurList;
            }

        }
    }

    if (usedSlots != 0)
        average = (double) totalElements / (double) usedSlots;


    printf("\tTotal elements on the list:\t\t%d\n", totalElements);
    printf("\tUsed slots on the table:\t\t%d\n", usedSlots);
    printf("\tMaximum elements on one slot:\t%d\n", maxLength);
    printf("\tAverage length of lists:\t\t%f\n", average);

}


/**
 * This function is also a debug function that we use for printing all the data in the table
 *
 * We iterate through all the positions and if is not NULL we print the key of the first element and all
 * the possible elements in the linked list.
 *
 * */
void printData(hashTable table) {

    if (table == NULL)
        return;                                        //If the the table is NULL then we cannot print it.

    int i;
    hashElement *currentElement;
    printf("\n\nPRINTING TABLE DATA:\n\n");

    for (i = 0; i < TABLESIZE; i++) {
        if (table[i] != NULL) {
            currentElement = table[i];
            printf("\tPOSITION %d:\t=>\t[%s]", i, currentElement->key);
            currentElement = currentElement->next;
            while (currentElement != NULL) {
                printf("->[%s]", currentElement->key);
                currentElement = currentElement->next;
            }
            printf("\n");
        }
    }
}

/**
 * A function used to call strcmp fir sorting all
 * the words inside the hashtable.
 *
 * */
int stringCmp(const void *a, const void *b) {
    const char **ia = (const char **) a;
    const char **ib = (const char **) b;
    return strcmp(*ia, *ib);
}


/**
 * Same as the function above but printing in alphabetical order.
 *
 * */
void printDataSorted(hashTable table, short vervose) {

    char **vectorOfStrings;                             //Our vector fo strings that will contain all keys from the hashtable.

    if (table == NULL)
        return;                                         //If the the table is NULL then we cannot print it.

    int i;
    hashElement *currentElement;
    if (vervose)
        printf("\n\nPRINTING TABLE DATA (sorted):\n\n");
    int numOfElements = 0;


    for (i = 0; i < TABLESIZE; i++) {                   //First we read the number of elements
        if (table[i] != NULL) {
            currentElement = table[i];
            numOfElements++;
            currentElement = currentElement->next;
            while (currentElement != NULL) {
                numOfElements++;
                currentElement = currentElement->next;
            }
        }
    }

    vectorOfStrings = (char **) malloc(((size_t) numOfElements) * sizeof(char *));

    int j = 0;                                          //Now we save all elements inside our array
    for (i = 0; i < TABLESIZE; i++) {
        if (table[i] != NULL) {
            currentElement = table[i];
            vectorOfStrings[j] = (char *) malloc((strlen(currentElement->key) + 1));    //Reserve memory for the word
            strcpy(vectorOfStrings[j], currentElement->key);                            //Copy it
            j++;
            currentElement = currentElement->next;
            while (currentElement !=
                   NULL) {                                            //Do this also for the sons of the elements
                if (currentElement->key != NULL && currentElement->data != NULL) {
                    vectorOfStrings[j] = (char *) malloc((strlen(currentElement->key) + 1));
                    strcpy(vectorOfStrings[j], currentElement->key);
                    j++;
                    currentElement = currentElement->next;
                } else {
                    break;
                }
            }
        }
    }

    qsort(vectorOfStrings, (size_t) numOfElements, sizeof(char *),
          stringCmp);          //Call a fast quicksort to sort all elements using the function above.


    for (i = 0; i < numOfElements; i++) {                                               //And we print all elements
        if (vervose)
            printf("\tElement %3d:\t=>\t[" CYN "%s" RESET "]\n", i, vectorOfStrings[i]);
        else {
            printf("\t[" CYN "%s" RESET "]", vectorOfStrings[i]);
            if ((i + 1) % 4 == 0) printf("\n");
        }
        free(vectorOfStrings[i]);                                                       //While we free em
    }
    free(vectorOfStrings);                                                              //Finally we free the whole vector of strings.

}


//ADHOC:
int stringCmpSD(const void *a, const void *b) {
    char **ia = &((variableContent *) ((*((const symbolData **) a))->content))->name;
    char **ib = &((variableContent *) ((*((const symbolData **) b))->content))->name;
    return strcmp(*ia, *ib);
}

void printAllVariables(hashTable table) {

    symbolData **vectorOfSD;

    if (table == NULL)
        return;                                         //If the the table is NULL then we cannot print it.

    int i;
    hashElement *currentElement;
    int numOfElements = 0;


    for (i = 0; i < TABLESIZE; i++) {                   //First we read the number of elements
        if (table[i] != NULL) {
            currentElement = table[i];
            numOfElements++;
            currentElement = currentElement->next;
            while (currentElement != NULL) {
                numOfElements++;
                currentElement = currentElement->next;
            }
        }
    }

    vectorOfSD = malloc(((size_t) numOfElements) * sizeof(symbolData *));

    int j = 0;                                          //Now we save all elements inside our array
    for (i = 0; i < TABLESIZE; i++) {
        if (table[i] != NULL) {
            currentElement = table[i];
            vectorOfSD[j] = (symbolData *) currentElement->data;
            j++;
            currentElement = currentElement->next;
            while (currentElement !=
                   NULL) {                                            //Do this also for the sons of the elements
                if (currentElement->key != NULL && currentElement->data != NULL) {
                    vectorOfSD[j] = (symbolData *) currentElement->data;
                    j++;
                    currentElement = currentElement->next;
                } else {
                    break;
                }
            }
        }
    }

    qsort(vectorOfSD, (size_t) numOfElements, sizeof(symbolData *),
          stringCmpSD);          //Call a fast quicksort to sort all elements using the function above.


    for (i = 0; i < numOfElements; i++) {                                               //And we print all elements
        if (((variableContent *) vectorOfSD[i]->content)->defined && (vectorOfSD[i]->type == TYPE_VARIABLE)) {


            printf("  [" CYN "%s" RESET "] with a size of [" CYN "%d" RESET "," CYN "%d" RESET "]",
                   ((variableContent *) vectorOfSD[i]->content)->name,
                   (((variableContent *) vectorOfSD[i]->content)->value).rows,
                   (((variableContent *) vectorOfSD[i]->content)->value).columns);

            printf(BLU"\n  Value: \n");
            printMatrix(((variableContent *) vectorOfSD[i]->content)->value);

            printf(RESET"\n");

            /*if ((i+1) % 4 == 0)*/ printf("\n");
        }
    }
    free(vectorOfSD);                                                              //Finally we free the whole vector of strings.

}