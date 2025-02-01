/***************************************
Definitions
***************************************/
#include "main_state.h"

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

// state machine cases Array
sm_fp sm_cases[] =
{

};


/***************************************
Prototypes
***************************************/

/***************************************
Variable
***************************************/
// State next is initialized is initialize state
static State_next s_state_next = STATE_INIT;


/***************************************
Code
***************************************/
// remove ASCII character Driver
void driver_remove_ASCII(char* input_link)
{
    // 
}
