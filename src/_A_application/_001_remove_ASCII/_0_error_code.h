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

#ifndef _ERR_CODE_H_
#define _ERR_CODE_H_
/***************************************
* Definitions
***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum 
{
    tempfile_OK,
    tempfile_FAILED_TO_CREATE,
    tempfile_FAILED_TO_OPEN,
    tempfile_FAILED_TO_RENAME,
    tempfile_FAILED_TO_REMOVE
} ret_temp_file;

typedef enum
{
    iofile_OK,
    iofile_FAILED_TO_CLOSE,
    iofile_FAILED_TO_OPEN,
    iofile_FAILED_ALLOC_BUFFER
} ret_file_io;

/***************************************
* API
***************************************/

/**
 * @brief print with separate line then input
 */
void print_something_then_input(const char* str_print);

/** 
 * @brief input string with max size identified
 * 
 * @param size Maxsize of string
 * @param input_str Input string
 * @return 0 if success, 1 if failed
 */
int input_string_dynamic_len(const char* size, char* input_str);

/**
 * @brief log temp file error details
 * @param return_code The type of error when interact with a temp file
 * @return 0 if no error, 1 if error
 */
int log_err_info(ret_temp_file return_code);

/**
 * @brief log file error details
 * @param return_code The type of error when interact with file stream
 * @return 0 if no error, 1 if error
 */
int log_err_info(ret_file_io return_code);

#endif /*_ERR_CODE_H_*/