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

#ifndef _TEMP_FILE_H_
#define _TEMP_FILE_H_
/***************************************
* Definitions
***************************************/
#include "_0_error_code.h"


// for linux and window :)
// define default temp locate
#ifdef _WIN32
#define TEMP_FOLDER ".\\"    

#elif defined(__linux__)
#define TEMP_FOLDER "./"   

#endif

// define template for temp file
#define TEMP_TEMPLATE "temp_" // template only <=4 , i tried >4 then the name file was unidentified

// standart libs
#include <stdio.h>
#include <stdlib.h>

/***************************************
* API
***************************************/

/**
 * @brief Create temp file
 * 
 * @param max_size MAX Size of link will create
 * @param link_ptr_p pointer to string pointer, save link created
 * 
 * @return check by log_err_info
 */
ret_temp_file create_a_temp_file(char** link_ptr_p, int max_size);

/**
 * @brief Rename_a_file
 * 
 * @param new_name Newlink to move file
 * @param old_name Oldlink want move
 * 
 * @return check log
 */
ret_temp_file rename_a_temp_file(char* new_name, char* old_name);


/**
 * @brief Delete a file
 * @param file_name File want delete
 */
ret_temp_file delete_a_temp_file(char* file_name);


#endif /* _TEMP_FILE_H_ */