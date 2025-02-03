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
    tempfile_OK
} ret_temp_file;

typedef enum
{
    iofile_OK,
    iofile_FAILED_TO_CLOSE,
    iofile_FAILED_TO_OPEN
} ret_file_io;

/***************************************
* API
***************************************/

/**
 * @brief print with separate line then input
 */
void print_something_then_input(char* str_print);

/** 
 * @brief input string with max size identified
 * 
 * @param size Maxsize of string
 * @param input_str Input string
 * @return 0 if success, 1 if failed
 */
int input_string_dynamic_len(char* size, char* input_str);

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