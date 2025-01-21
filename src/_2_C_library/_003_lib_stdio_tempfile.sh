#!/bin/bash

g++ -std=c++0x _003_lib_stdio_tempfile.cpp -o ./build/_003_lib_stdio_tempfile.out

clear

cd build/

./_003_lib_stdio_tempfile.out

cd ../