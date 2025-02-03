/***************************************
Definitions
***************************************/
#include "main_state.h"

/***************************************
Prototypes
***************************************/

/***************************************
Variable
***************************************/

/***************************************
Code
***************************************/
/**
 * @brief main fuction
 * 
 * @return
 * 0 - no problem
 * 
 * not 0 - call menu for more inform
 */
int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        fprintf(stderr,"\n INPUT NOTHING \n");
        fprintf(stderr,"Syntax: ./run_app.out [link to text file]\n");
        return 1;
    }

    // if input menu -> menu
    // if input sonething else -> check


    if(driver_remove_ASCII(argv[1]))
    {
        return 2;
    }

    // anything ok
    fprintf(stderr,"\n EXIT OKEY \n");
    return 0;    
}
