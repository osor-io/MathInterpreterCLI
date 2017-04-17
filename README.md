# MathInterpreterCLI (WolframBeta)
An interpreter for mathematical expressions similar to a command line while learning Flex and Bison and its integration. Supports all commonly used operations with single numbers, vectors and matrices (with floats, integers, booleans, etc).

To compile the program you can use the compile.sh found on the /scripts/ folder and then use run.sh or runWithLoad.sh to test it.

If you want to compile the program but you dont have cmake or make in your system you could compile it with the next flex, bison and gcc commands (should be executed in /src/(the gcc) and /src/Flex\&Bison (flex and bison commands)):

```bash
flex mainFlex.l 

bison -v -d mainBison.y 

gcc main.c ./readerSystem/readerSystem.c ./readerSystem/readerSystem.h ./errorManager/errorManager.c ./errorManager/errorManager.h ./symbolTable/symbolTable.c ./symbolTable/symbolTable.h utils/bHashTable.c utils/bHashTable.h utils/colours.h utils/defineParser.c utils/defineParser.h Flex\&Bison/CLIHelp.c Flex\&Bison/CLIHelp.h -Wall -Wextra -lm
```

Then you could execute it yourself with:

```bash
./a.out [-l file_to_load]
```
