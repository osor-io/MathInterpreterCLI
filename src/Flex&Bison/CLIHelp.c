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

    printf(GRN"\t\t====================================\n");
    printf(   "\t\t=========SUPPORTED COMMANDS=========\n");
    printf(   "\t\t====================================\n\n\n"RESET);

    printReservedWords(global_st);

    printf(GRN"\nOPERATORS CURRENTLY SUPPORTED:\n"RESET);

    printf(BLU "    ["RED" / "BLU"] : second element has to be a single element\n" RESET);
    printf(BLU "	["RED" /= "BLU"] : second element has to be a single element\n" RESET);
    printf(BLU "	["RED" && "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" || "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" - "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" -= "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" -- "BLU"] : supported only for single elements\n" RESET);
    printf(BLU "	["RED" + "BLU"] : supported matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" += "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" ++ "BLU"] : supported only for single elements\n" RESET);
    printf(BLU "	["RED" < "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" <= "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" > "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" >= "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" ! "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" != "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" ( and ) "BLU"] : used for group expressions\n" RESET);
    printf(BLU "	["RED" [ and ] "BLU"] : supported for access to vectors and matrices\n" RESET);
    printf(BLU "	["RED" ; "BLU"] : used for hide the answer in the console (put at the end of the line)\n" RESET);
    printf(BLU "	["RED" = "BLU"] : assigns single elements and matrices\n" RESET);
    printf(BLU "	["RED" == "BLU"] : supported for matrices and single element as second operand\n" RESET);
    printf(BLU "	["RED" * "BLU"] : supported for multiplying matrices and single elements\n" RESET);
    printf(BLU "	["RED" *= "BLU"] : supported for multiplying matrices and single elements\n" RESET);
    printf(BLU "	["RED" %% "BLU"] : second element has to be a single element\n" RESET);
    printf(BLU "	["RED" %%= "BLU"] : second element has to be a single element\n" RESET);

    printf(GRN"\n\nOTHER RESERVED WORDS:\n"RESET);

    printf(BLU "    ["RED" clear "BLU"] : Clears and deletes all the variables\n" RESET);
    printf(BLU "    ["RED" who "BLU"] : Prints all the variables defined\n" RESET);
    printf(BLU "    ["RED" dec "BLU"] : Declares a variable, vector or matrix, example: dec var[size][size]\n" RESET);
    printf(BLU "    ["RED" help "BLU"] : Shows help, you probably already know this :)\n" RESET);
    printf(BLU "    ["RED" exit/quit "BLU"] : Quits the program.\n" RESET);

    printf(GRN"\n\nLITERALS:\n"RESET);

    printf(BLU "    ["RED" Integers "BLU"] : With the usual sintax\n" RESET);
    printf(BLU "    ["RED" Hexadecimal "BLU"] : Starting with '0X' or '0x'\n" RESET);
    printf(BLU "    ["RED" Floats "BLU"] : Using a point before decimals and allowing exponentials, example: 1.12e+19\n" RESET);
    printf(BLU "    ["RED" Constants like 'pi' and 'e' "BLU"] : With their usual values\n" RESET);

    printf("\n\n");




    helpCounter++;


}