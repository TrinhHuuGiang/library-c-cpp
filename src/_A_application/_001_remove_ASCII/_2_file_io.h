/*
IO streams for Remove ASCII program
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

#ifndef _FILE_IO_H_
#define _FILE_IO_H_
/***************************************
* Definitions
***************************************/
#include "_0_error_code.h"

#define PAGE_SIZE_BUFFER (4096) // 4KB

// standart libs
#include <stdio.h>


/***************************************
* API
***************************************/

/**
 * @brief Open file stream with r+ mode
 * @param link string include link to text file
 * @param file_ptr_p a pointer to file pointer, sure that we can point new FILE stream to FILE pointer
 */
ret_file_io open_file_rw_mode_stream(char* link, FILE** file_ptr_p);

/**
 * @brief Close file stream
 * @param file_ptr_p a pointer to file pointer, sure that after call function the FILE* point to NULL
 */
ret_file_io close_file_stream(FILE** file_ptr_p);

/**
 * @brief Set buffer for stream
 * 
 * Sure that write operation is minimal for disk for extend hard drive life
 * 
 * PAGE_SIZE_BUFFER will be default size for buffer
 * @param file_p a pointer to file pointer, sure that after call function the FILE* point to NULL
 */
ret_file_io set_full_buffer_stream(FILE* file_p);

#endif /* _FILE_IO_H_ */