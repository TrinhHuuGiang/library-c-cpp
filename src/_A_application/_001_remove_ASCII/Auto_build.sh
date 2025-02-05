#!/bin/bash

echo -e "\nCompiling 'Remove ASCII' ...."

g++ -std=c++0x -o ./build/ascii_remove.out remove_main.cpp remove_state.cpp libs/_0_error_code.cpp libs/_1_temp_file.cpp libs/_2_file_io.cpp

echo -e "\nCompiling 'Convert ASCII to space'...."

g++ -std=c++0x -o ./build/ascii_to_space.out c_space_main.cpp c_space_state.cpp libs/_0_error_code.cpp libs/_1_temp_file.cpp libs/_2_file_io.cpp

echo -e "\nDone."