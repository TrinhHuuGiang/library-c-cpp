/***************************************
Definitions
***************************************/
#include "_2_file_io.h"

/***************************************
Prototypes
***************************************/

/***************************************
Variable
***************************************/

/***************************************
Code
***************************************/

// open FILE stream, read/write mode
ret_file_io open_file_rw_mode_stream(char* link, FILE** file_ptr_p)
{
    // try close if FILE* not NULL
    if(*file_ptr_p != NULL)
    {
        if(fclose(*file_ptr_p) == EOF)
        {
            return iofile_FAILED_TO_CLOSE;
        }
        //else if close success, point it to NULL
        *file_ptr_p = NULL;
    }

    // try open file if right link
    *file_ptr_p = fopen(link, "r+");
    if(*file_ptr_p == NULL)
    {
        return iofile_FAILED_TO_OPEN;
    }

    // if open success
    return iofile_OK;
}

// close file stream
ret_file_io close_file_stream(FILE** file_ptr_p)
{
    // try close if FILE* not NULL
    if(*file_ptr_p != NULL)
    {
        if(fclose(*file_ptr_p) == EOF)
        {
            return iofile_FAILED_TO_CLOSE;
        }
        //else if close success, point it to NULL
        *file_ptr_p = NULL;
    }

    // ok
    return iofile_OK;
}

// set full buffer mode
ret_file_io set_full_buffer_stream(FILE* file_p)
{
    // setvbuf return 0 if success
    if(setvbuf(file_p,NULL, _IOFBF, PAGE_SIZE_BUFFER))
    {
        return iofile_FAILED_ALLOC_BUFFER;
    }

    //exit
    return iofile_OK;
}