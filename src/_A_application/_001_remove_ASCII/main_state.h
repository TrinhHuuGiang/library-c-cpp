#ifndef _MAIN_STATE_H_
#define _MAIN_STATE_H_
/***************************************
* Definitions
***************************************/
// self define
#include "_0_error_code.h"

#include "_1_temp_file.h"
#include "_2_file_io.h"

// standart libs


// state machine index in function pointer array
typedef enum
{
    STATE_INIT = 0,                   //initial state with link was inputted to text file
    STATE_REINPUT_LINK,               //re-input state when user input wrong path
    STATE_COUNT_ASCII,                //count number ASCII are existing in text file
    STATE_CHOOSE_CHARACTER_TO_DELETE, //user choose a ASCII character to delete
    STATE_DELETE_CHARACTER,           //delete ASCII charater was chosen
    STATE_END                         //end driver
} State_next;

/**
 * @brief State Function Pointer
 * 
 * Function pointer for each state in the state machine.
 * 
 * @param None
 * @return State_next The next state index
 */
typedef State_next (*sm_fp)();


/***************************************
* API
***************************************/
/**
 * @brief Remove some ASCII character in text file
 * 
 * @param input_link The link (string) to the text file want delete ASCII character
 */
void driver_remove_ASCII(char* input_link);

#endif /* _MAIN_STATE_H_ */