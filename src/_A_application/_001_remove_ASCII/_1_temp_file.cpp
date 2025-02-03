/*
Create temporary file for Remove ASCII program
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
#include "_1_temp_file.h"

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
