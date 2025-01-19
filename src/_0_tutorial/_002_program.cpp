// Two types of comments: // (single-line) and /* */ (multi-line)

/*
Lines starting with # are handled by the 'preprocessor' before the actual compilation of the source code.
*/
#include <iostream>
#define A 10

/**
 * @brief ['main' Funtion]
 * 
 * 'main' is a special function that is always the entry point of the program.
 * It is the first function to run when the program starts.
 * 
 * @param 'argc': The count of command-line arguments passed to the program,
 * including the program name. Default value is 1 if no additional arguments are provided.
 * 
 * @param 'argv': An array of strings containing the command-line arguments.
 * The first element (argv[0]) is the program name or path.
 * 
 * @return 'return': The default return value is 0, indicating successful execution.
 * we can define other directive 0 like 1 , 2 ,... to note some error.
 * 
 * @note
 * cursor on main function to read familiar.
*/
int main(int argc, char* argv[])
{
    // Your code goes here

    // end
    return 0;
}
