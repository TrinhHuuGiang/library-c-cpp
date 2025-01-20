// go to: src/_2_C_library
// build: g++ -std=c++0x _001_lib_assert.cpp -o ./build/_001_lib_assert.out
// run: ./build/_001_lib_assert.out

/*
Library: <cassert> or <assert.h>
Function:
- assert:
    - is a macro function
    - syntax:
        - void assert (int expression);
    - purpose:
        - If the argument 'expression' is 'false', a message is written to standart error stream 'stderr'
        to show area error.
        - To disable 'assert' when complete debug, we can define macro name NDEBUG before include <assert.h>

*/

// #define NDEBUG //un comment this line to start assert while debugging
#include<cassert>
#include<iostream>
#include<cstdio>

using namespace std;

int main(int argc, char* argv[])
{
    int a = 10, b = 20;

    assert(a>b); // if not define NDEBUG, this line do nothing, else close with error info, error code

    cout<<"No define NDEBUG"<<endl;
    
    fflush(stdin);
    cout<<"Press any key to end"<<endl;
    getchar();
    return 0;
}

