/*
Error codes for Remove ASCII program
Copyright (C) 2025  Giang Trinh.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/***************************************
* Definitions
***************************************/
#include "_0_error_code.h"


/***************************************
Code
***************************************/
// print with separate line then input
void print_something_then_input(const char* str_print)
{
    fprintf(stderr, "\n");
    for(int i = 0; i<20;i++)
        fprintf(stderr,"|");
    fprintf(stderr, "\n%s\n->" ,str_print);
}

// input long string limited length
int input_string_dynamic_len(const char* size, char* input_str)
{
    char* template_scanf = (char*)calloc(strlen(size)+10,sizeof(char));
    if(template_scanf == NULL)
    {
        fprintf(stderr, "[Allocate Failed] - %s, %d\n", __FILE__, __LINE__);
        return 1;
    }

    // concatenate
    template_scanf[0]='%';//1
    strcat(template_scanf, size);//size
    strcat(template_scanf, "[^\n]%*c");//8 -> 10 (+ 1 for null)

    // end
    scanf(template_scanf, input_str);
    free(template_scanf);

    return 0;
}

// temp file log
int log_err_info(ret_temp_file return_code)
{
    switch (return_code)
    {
        case tempfile_FAILED_TO_CREATE:
        case tempfile_FAILED_TO_OPEN:
        case tempfile_FAILED_TO_RENAME:
        case tempfile_FAILED_TO_REMOVE:

            perror("[ERR temp file]");
            fprintf(stderr,"[%d]\n", return_code);
            return 1;
        
        case tempfile_OK:
            return 0;

        default:
            perror("[ERR unexpected]");
            return 1;
    }
}

// io file log
int log_err_info(ret_file_io return_code)
{
    switch (return_code)
    {
        case iofile_FAILED_TO_CLOSE:
        case iofile_FAILED_TO_OPEN:
        case iofile_FAILED_ALLOC_BUFFER:

            perror("[ERR file io]");
            fprintf(stderr,"[%d]\n", return_code);
            return 1;
        
        case iofile_OK:
            return 0;

        default:
            perror("[ERR unexpected]");
            return 1;
    }
}
