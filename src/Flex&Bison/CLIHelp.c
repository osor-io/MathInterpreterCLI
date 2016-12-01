//
// Created by Rubén Osorio López on 1/12/16.
//

#include "./CLIHelp.h"
#include <stdio.h>
#include "../utils/colours.h"
#include "../symbolTable/symbolTable.h"


extern symbolTable *global_st;


short helpCounter = 0;

#define REQUIRED_HELP 4

void printfHelp() {


    if (helpCounter > REQUIRED_HELP) {
        switch (helpCounter) {
            case (REQUIRED_HELP + 1):
                printf(MAG"I need somebody\n"RESET);
                break;
            case (REQUIRED_HELP + 2):
                printf(MAG"Not just anybody\n"RESET);
                break;
            case (REQUIRED_HELP + 3):
                printf(MAG"You know I need someone\n"RESET);
                break;
            default:
                helpCounter = 0;
        }
    }

    printf("SUPPORTED COMMANDS:\n\n");

    printReservedWords(global_st);


    helpCounter++;


}