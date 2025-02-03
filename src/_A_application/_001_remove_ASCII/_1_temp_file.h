#ifndef _TEMP_FILE_H_
#define _TEMP_FILE_H_
/***************************************
* Definitions
***************************************/
#include "_0_error_code.h"

// standart libs
#include <stdio.h>

/***************************************
* API
***************************************/
ret_temp_file create_a_temp_file();

ret_temp_file rename_a_temp_file();

ret_temp_file delete_a_temp_file();


#endif /* _TEMP_FILE_H_ */