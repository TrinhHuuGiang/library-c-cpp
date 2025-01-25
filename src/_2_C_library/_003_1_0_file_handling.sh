#!/bin/bash

# ------------------------------------
# Variable
# ------------------------------------
PATH_to_build="./build/"
PATH_to_temp="./build/temp/"

temp_file_cpp="_003_1_1_tempfile.cpp"
temp_file_out="_003_1_1_tempfile.out"

rename_cpp="_003_1_2_rename.cpp"
rename_out="_003_1_2_rename.out"

your_choice="N"

# ------------------------------------
# Compile
# ------------------------------------
# [temp file]
g++ -std=c++0x $temp_file_cpp -o $PATH_to_build$temp_file_out
# [rename file]
g++ -std=c++0x $rename_cpp -o $PATH_to_build$rename_out

# ------------------------------------
# create tempfile
# ------------------------------------
# clear

mkdir -p "$PATH_to_temp"

cd "$PATH_to_build"
# cd 'build' because execute file in 'build'.
# shouldn't call execute file when in another folder
# temp file will created maybe not in expected 'temp' folder

"./$temp_file_out"

cd ../

# ------------------------------------
# rename tempfile
# ------------------------------------
# clear
while [ "$your_choice" != "Y" ]
do
    echo -e "Do you want to rename temp files (Y/N)\nYour choice: "
    read your_choice

    if [ "$your_choice" == "N" ]; then
        echo "[End]"
        exit 0
    fi
done

"$PATH_to_build$rename_out" "$PATH_to_temp"
