/***************************************
* Definitions
***************************************/
#include "_1_temp_file.h"

/***************************************
Prototypes
***************************************/

/***************************************
Variable
***************************************/

/***************************************
Code
***************************************/

// create temp file
ret_temp_file create_a_temp_file(char** link_ptr_p, int max_size)
{
    // try clear if char* not NULL
    if(*link_ptr_p != NULL)
    {
        free(*link_ptr_p);
        *link_ptr_p = NULL;
    }

    // try create temp file name
    *link_ptr_p = tempnam(TEMP_FOLDER, TEMP_TEMPLATE);
    if(*link_ptr_p == NULL)
    {
        return(tempfile_FAILED_TO_CREATE);
    }

    // create file real
    {
        FILE* file_p = fopen(*link_ptr_p, "a+");
        if( file_p == NULL)
        {
            return(tempfile_FAILED_TO_OPEN);
        }
        fclose(file_p);
    }

    // exit
    return tempfile_OK;
}

// rename
ret_temp_file rename_a_temp_file(char* new_name, char* old_name)
{
    // rename
    if(rename(old_name, new_name))
    {
        return tempfile_FAILED_TO_RENAME;
    }

    // exit
    return tempfile_OK;
}

// delete
ret_temp_file delete_a_temp_file(char* file_name)
{
    // remove
    if(remove(file_name))
    {
        return tempfile_FAILED_TO_REMOVE;
    }

    // exit
    return tempfile_OK;
}
