cmake_minimum_required(VERSION 3.6)
project(micli)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  main.c ./readerSystem/readerSystem.c ./readerSystem/readerSystem.h ./errorManager/errorManager.c ./errorManager/errorManager.h ./symbolTable/symbolTable.c ./symbolTable/symbolTable.h utils/bHashTable.c utils/bHashTable.h utils/colours.h utils/defineParser.c utils/defineParser.h Flex&Bison/CLIHelp.c Flex&Bison/CLIHelp.h)
add_executable(micli ${SOURCE_FILES})