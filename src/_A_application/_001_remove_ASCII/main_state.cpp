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
static char* s_temp_link = NULL;  

/***************************************
Code
***************************************/
// Check input link
static State_next Check_input_link(char* input_link)
{
    int file_open = 0;     // 0 is not open
    FILE* file_ptr = NULL; // pointer to file stream when is opened

    // create new heap to save link
    s_input_link = (char*)calloc(MAX_LINK_LENGTH, sizeof(char));
    if(s_input_link == NULL)
    {
        fprintf(stderr, "[Allocate Failed] - %s, %d\n", __FILE__, __LINE__);
        return STATE_END;
    }

    // copy string for safe main pointer of pointer 'input_link'
    // if input_link == NULL so equal empty then next step
    if(input_link != NULL)
    {
        strcpy(s_input_link , input_link);
        fprintf(stderr,"\n[input link] %s\n", s_input_link);
    }
    
    // check file can open
    while(!file_open)
    {
        fprintf(stderr, "Opening File ... \n");
        // open file
        // some function check file open here
        // if open ok file_open = 1, then go next state
        if(!log_err_info(open_file_rw_mode_stream(s_input_link, &file_ptr)))
        {
            file_open = 1;
        }

        // if can't using this link, or can't open streams to file
        // reset array then re-input
        if(!file_open)
        {
            int i = 'x';
            do
            {
                print_something_then_input("[Failed open] continue (y/n)?");
                i = getchar();
            } while (i != 'y' && i != 'Y' && i != 'N' && i != 'n');
            fgetc(stdin);

            // if want close
            if(i == 'N' || i == 'n')
            {
                return STATE_END;
            }

            // else if want continue
            memset(s_input_link,0,MAX_LINK_LENGTH);
            print_something_then_input("Re-input your link text file:");
            input_string_dynamic_len(MAX_LINK_LENGTH_s, s_input_link);
        }
    }

    // close FILE stream
    if(log_err_info(close_file_stream(&file_ptr)))
    {
        return STATE_END;
    }

    // no free s_input_link, using it for future
    // go next state
    return STATE_COUNT_ASCII;
}

// Count ASCII
static State_next Count_ASCII_character()
{
    FILE* file_ptr = NULL; // pointer to file stream when is opened
    // Each element in the table is an index-separated number of ASCII characters of the dynamic array
    int* ASCII_count_table = (int*)calloc(USING_ASCII, sizeof(int));

    // open file
    if(log_err_info(open_file_rw_mode_stream(s_input_link, &file_ptr)))
    {
        return STATE_END;
    }

    // count
    rewind(file_ptr);
    {
        int c = fgetc(file_ptr);
        while(c != EOF)
        {
            if(c<USING_ASCII)
            {
                ASCII_count_table[c] ++;
                c = fgetc(file_ptr);
            }
            else
            {
                fprintf(stderr,"[WARN overflow] - %s, %d", __FILE__, __LINE__);
            }
        }
    }

    // print table
    print_something_then_input("ASCII table counted:");
    {
        // check 0-31 , 127
        int check_print = 0; // 0 - can print
        for(int i= 0 ; i< USING_ASCII ; i++)
        {
            // split line. 5 for each line
            if(i%5 == 0)
            { fprintf(stderr,"\n"); }

            // print index of ASCII
            fprintf(stderr,"[%3d]", i);// -> 5 char

            // check non-print character
            if(iscntrl(i)) // 0-31 , 127
            {
                char s[5] = {0};
                switch (i)
                {
                    case 0: strcat(s,"NULL");break;
                    case 1: strcat(s,"SOH ");break;
                    case 2: strcat(s,"STX ");break;
                    case 3: strcat(s,"ETX ");break;
                    case 4: strcat(s,"EOT ");break;
                    case 5: strcat(s,"ENQ ");break;
                    case 6: strcat(s,"ACK ");break;
                    case 7: strcat(s,"BEL ");break;
                    case 8: strcat(s,"BS  ");break;
                    case 9: strcat(s,"HT  ");break;
                    case 10: strcat(s,"LF  ");break;
                    case 11: strcat(s,"VT  ");break;
                    case 12: strcat(s,"FF  ");break;
                    case 13: strcat(s,"CR  ");break;
                    case 14: strcat(s,"SO  ");break;
                    case 15: strcat(s,"SI  ");break;
                    case 16: strcat(s,"DLE ");break;
                    case 17: strcat(s,"DC1 ");break;
                    case 18: strcat(s,"DC2 ");break;
                    case 19: strcat(s,"DC3 ");break;
                    case 20: strcat(s,"DC4 ");break;
                    case 21: strcat(s,"NAK ");break;
                    case 22: strcat(s,"SYN ");break;
                    case 23: strcat(s,"ETB ");break;
                    case 24: strcat(s,"CAN ");break;
                    case 25: strcat(s,"EM  ");break;
                    case 26: strcat(s,"SUB ");break;
                    case 27: strcat(s,"ESC ");break;
                    case 28: strcat(s,"FS  ");break;
                    case 29: strcat(s,"GS  ");break;
                    case 30: strcat(s,"RS  ");break;
                    case 31: strcat(s,"US  ");break;
                    case 127: strcat(s,"DEL ");break;
                
                default:
                    break;
                }
                fprintf(stderr,"%s:%4d|",s, ASCII_count_table[i]);// -> 10 char
            }

            // check print character
            else
            {
                fprintf(stderr,"%-4c:%4d|", i, ASCII_count_table[i]);
            }
        }
    }

    // close FILE stream
    if(log_err_info(close_file_stream(&file_ptr)))
    {
        return STATE_END;
    }

    // free
    free(ASCII_count_table);

    // go next state
    return STATE_CHOOSE_CHARACTER_TO_DELETE;
}

// Choose an ASCII
static State_next Choose_ASCII_to_delete()
{
    int c;

    // user input 0 -> max ASCII character
    // check, re-input untill ok
    do
    {
        print_something_then_input("Input your ASCII want to delete:");
        fprintf(stderr, "[0-%d]", USING_ASCII-1);
        c = getchar();
    } while (c < 0 || c >= USING_ASCII);
    if((char)c != '\n')
    { fgetc(stdin); }

    // ask sure -> next state or ask continue -> replay count state or end state
    do
    {
        print_something_then_input("Are you sure detele? (y/n)");
        c = getchar();
    } while (c != 'y' && c != 'Y' && c != 'N' && c != 'n');
    fgetc(stdin);

    // if not want delete
    if(c == 'N' || c == 'n')
    {
        // continue ?
        do
        {
            print_something_then_input("Continue delete other ASCII? (y/n)");
            c = getchar();
        } while (c != 'y' && c != 'Y' && c != 'N' && c != 'n');
        fgetc(stdin);

        // end
        if(c == 'N' || c == 'n')
        {
            return STATE_END;
        }
        
        // Delete other ASCII
        return STATE_COUNT_ASCII;
    }
    
    // next delete state
    return STATE_DELETE_CHARACTER;
}

// Delete the ASCII was chosen
static State_next Delete_ASCII_chosen()
{


    // end state
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
                if(s_input_link != NULL)
                {
                    free(s_input_link);
                    s_input_link = NULL;
                }
                if(s_temp_link != NULL)
                {
                    free(s_temp_link);
                    s_temp_link = NULL;
                }

                _loop_ = 0;
                break;

            default:
                return 1;
        }
    }
    return 0;
}
