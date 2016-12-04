#!/usr/bin/env bash

cd ../src/Flex\&Bison/
./compile.sh
cd ../../bin
cmake -DCMAKE_BUILD_TYPE=Release ../src/
make
