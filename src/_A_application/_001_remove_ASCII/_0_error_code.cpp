/***************************************
* Definitions
***************************************/
#include "_0_error_code.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/***************************************
Prototypes
***************************************/

/***************************************
Variable
***************************************/

/***************************************
Code
***************************************/
// print with separate line then input
void print_something_then_input(char* str_print)
{
    fprintf(stderr, "\n");
    for(int i = 0; i<20;i++)
        fprintf(stderr,"|");
    fprintf(stderr, "%s\n->" ,str_print);
}

int input_string_dynamic_len(char* size, char* input_str)
{
    char* template_scanf = (char*)calloc(strlen(size)+10,sizeof(char));
    if(template_scanf == NULL)
    {
        fprintf(stderr, "[Allocate Failed] - %s, %s\n", __FILE__, __LINE__);
        return 1;
    }

    // concatenate
    template_scanf[0]='%';//1
    strcat(template_scanf, size);//size
    strcat(template_scanf, "[^\n]%*c");//8 -> 10 (+ 1 for null)

    // end
    scanf(template_scanf, input_str);
    free(template_scanf);
    fflush(stdin);
}

void log_err_info(ret_temp_file return_code)
{
    // switch (return_code)
    // {
    //     case constant expression:
    //         /* code */
    //         break;
        
    //     default:
    //         break;
    // }
}

void log_err_info(ret_file_io return_code)
{
    // switch (return_code)
    // {
    //     case constant expression:
    //         /* code */
    //         break;
        
    //     default:
    //         break;
    // }
}
