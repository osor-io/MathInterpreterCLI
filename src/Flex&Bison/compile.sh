#!/bin/bash

flex mainFlex.l
bison mainBison.y

# gcc lex.yy.c 
# ./a.out ../../../bin/arguments/regression.d
