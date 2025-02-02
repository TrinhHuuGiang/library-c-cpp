#ifndef _ERR_CODE_H_
#define _ERR_CODE_H_
/***************************************
* Definitions
***************************************/
typedef enum 
{

} ret_temp_file;

typedef enum
{

} ret_file_io;

/***************************************
* API
***************************************/
// print with separate line then input
void print_something_then_input(char* str_print);

/** 
 * @brief input string with max size identified
 * 
 * @param size Maxsize of string
 * @param input_str Input string
 * @return 0 if success, 1 if failed
 */
int input_string_dynamic_len(char* size, char* input_str);

void log_err_info(ret_temp_file return_code);

void log_err_info(ret_file_io return_code);

#endif