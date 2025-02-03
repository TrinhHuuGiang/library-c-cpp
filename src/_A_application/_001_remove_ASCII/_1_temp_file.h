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