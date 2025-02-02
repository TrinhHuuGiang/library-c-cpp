/***************************************
Definitions
***************************************/
#include "main_state.h"

/***************************************
Prototypes
***************************************/
/**
 * @brief For State initial, input or re-input link go to text file
 * 
 * @param input_link check input link syntax
 * @return Next state
 */
static State_next Check_input_link(char* input_link);

/**
 * @brief Release table ASCII all character was counted
 * 
 * @return Next state
 */
static State_next Count_ASCII_character();

/**
 * @brief User choose an ASCII character to delete
 * 
 * @return Next state
 */
static State_next Choose_ASCII_to_delete();

/**
 * @brief Delete the ASCII character was chosen 
 * 
 * @return Next state
 */
static State_next Delete_ASCII_chosen();

/***************************************
Variable
***************************************/
// State next is initialized is initialize state
static State_next s_state_next = STATE_REINPUT_LINK;
static char* s_input_link = NULL;

/***************************************
Code
***************************************/
// Check input link
static State_next Check_input_link(char* input_link)
{
    int file_open = 0; // 0 is not open

    // create new heap to save link
    s_input_link = (char*)calloc(MAX_LINK_LENGTH, sizeof(char));
    if(s_input_link == NULL)
    {
        fprintf(stderr, "[Allocate Failed] - %s, %s\n", __FILE__, __LINE__);
        return STATE_END;
    }

    // copy string for safe main pointer of pointer 'input_link'
    // if input_link == NULL so equal empty then next step
    if(input_link != NULL)
    {
        strcpy(s_input_link , input_link);
    }
    
    // check file can open
    while(!file_open)
    {
        // open file
        // some function check file open here
        // if open ok file_open = 1, then do no thing


        // reset array then re-input
        if(!file_open)
        {
            char i = 'x';
            do
            {
                print_something_then_input("[Failed open] continue (y/n)?");
                i = getchar();
            } while (i != 'y' && i != 'Y' && i != 'N' && i != 'n');

            // if want close
            if(i == 'N' || i == 'n')
            {
                free(s_input_link);
                return STATE_END;
            }

            // else if want continue
            memset(s_input_link,0,MAX_LINK_LENGTH);
            print_something_then_input("Re-input your link text file:");
            input_string_dynamic_len(MAX_LINK_LENGTH_s, s_input_link);
        }
    }
    // no free s_input_link, using it for future
    return STATE_COUNT_ASCII;
}

// Count ASCII
static State_next Count_ASCII_character()
{

    return STATE_CHOOSE_CHARACTER_TO_DELETE;
}

// Choose an ASCII
static State_next Choose_ASCII_to_delete()
{

    return STATE_DELETE_CHARACTER;
}

// Delete the ASCII was chosen
static State_next Delete_ASCII_chosen()
{

    return STATE_END;
}

// remove ASCII character Driver
int driver_remove_ASCII(char* input_link)
{
    int _loop_ = 1;

    // auto run states
    while(_loop_)
    {
        switch (s_state_next)
        {
            case STATE_REINPUT_LINK:
                s_state_next = Check_input_link(input_link);
                break;
            case STATE_COUNT_ASCII:
                s_state_next = Count_ASCII_character();
                break;
            case STATE_CHOOSE_CHARACTER_TO_DELETE:
                s_state_next = Choose_ASCII_to_delete();
                break;
            case STATE_DELETE_CHARACTER:
                s_state_next = Delete_ASCII_chosen();
                break;
            case STATE_END:
                _loop_ = 0;
                break;
            default:
                return 1;
        }
    }
    return 0;
}
