// go to: src/_2_C_library
// build: g++ -std=c++0x _002_lib_ctype.cpp -o ./build/_002_lib_ctype.out
// run: ./build/_002_lib_ctype.out

#include<iostream>
#include<ctype.h>

#define a 10 //10 is LF in ASCII table
#define b '?'
#define c 'c'

using namespace std;

int main()
{
    // isalnum
    cout<<"isalnum a: "<<isalnum(a)<<endl; // false/ 0
    cout<<"isalnum b: "<<isalnum(b)<<endl; // false/ 0
    cout<<"isalnum c: "<<isalnum(c)<<endl; // true / !0



}