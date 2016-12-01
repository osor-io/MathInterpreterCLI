#!/bin/bash

flex mainFlex.l
bison -v  -d mainBison.y

# gcc lex.yy.c
# ./a.out ../../../bin/arguments/regression.d
