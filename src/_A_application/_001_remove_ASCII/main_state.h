/*
State machine for Remove ASCII program
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

#ifndef _MAIN_STATE_H_
#define _MAIN_STATE_H_
/***************************************
* Definitions
***************************************/
// self define
#include "_0_error_code.h"

#include "_1_temp_file.h"
#include "_2_file_io.h"

#define MAX_LINK_LENGTH (256)
#define MAX_LINK_LENGTH_s "255"

#define STANDART_ASCII (128)
#define FULL_ASCII     (256)
#define USING_ASCII    FULL_ASCII

// standart libs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// state machine index in function pointer array
typedef enum
{
    STATE_REINPUT_LINK,               //input and re-input state when user input wrong path
    STATE_COUNT_ASCII,                //count number ASCII are existing in text file
    STATE_CHOOSE_CHARACTER_TO_DELETE, //user choose a ASCII character to delete
    STATE_DELETE_CHARACTER,           //delete ASCII charater was chosen
    STATE_END                         //end driver
} State_next;

/***************************************
* API
***************************************/

/**
 * @brief Remove some ASCII character in text file
 * 
 * @param input_link The link (string) to the text file want delete ASCII character
 * @return 0 if no problem, 1 if unexpected
 */
int driver_remove_ASCII(char* input_link);

#endif /* _MAIN_STATE_H_ */