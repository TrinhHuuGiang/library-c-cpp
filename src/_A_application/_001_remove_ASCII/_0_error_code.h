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
void log_err_info(ret_temp_file return_code);

void log_err_info(ret_file_io return_code);

#endif