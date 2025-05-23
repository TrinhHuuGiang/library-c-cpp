## Library: stdio.h
- This library provides functions for input/output operations using "streams."
- A "stream" is an abstraction that represents a source or destination of data, 
  such as files, devices (keyboards, printers, terminals), or other data sources supported by the system.

- A pointer to a 'FILE' object uniquely identifies a stream and is used as a parameter 
  in functions that operate on the stream.

- The library provides three default standard 'FILE' streams:
  1. stdin  - Standard input stream (usually the keyboard).
  2. stdout - Standard output stream (usually the screen or a file).
  3. stderr - Standard error stream (usually the screen for error messages).
<hr>

## Funtions
1. File handling  
- tmpfile  
    - perpose: create new temp file, then delete it when end 'fclose()' or end program.   
    - syntax: `FILE* tmpfile(void);`  
    - return: NULL if failed, !NULL if success.  
- tempnam
    - note that this function only create file name unique, but not create file.  
    - perpose: create new tempfile name. 
    - syntax: `char* tempnam(const char *__dir, const char *__pfx);`  
    - return: 
        - if `__dir`, `__pfx` pointer is `NULL`, default an internal buffer will allocated.  
        - if return `NULL` - failed  
- rename  
    - perpose: rename, depend on system we can: move, overwrite exist file.  
    - syntax: `int rename(const char* oldname, const char* newname);`  
    - return: 0 if success, !0 if failed (check errno)  
- remove  
    - perpose: Delete file with file name.  
    - syntax: `int remove ( const char* filename );`  
    - return: 0 if success, !0 if failed (check errno)  
<br>

2. Stream handling
- **Overview**:
  - 
- fopen  
  - perpose: with the 'file name' and 'mode' we create a stream can interact with file  
  - syntax: `FILE * fopen ( const char * filename, const char * mode );`  
  - mode: https://cplusplus.com/reference/cstdio/fopen/  
  - return: NULL if failed, FILE pointer if succes.  
- fclose  
  - perpose: close stream after done work with file  
  - syntax: `int fclose ( FILE * stream );`  
  - return: 0 if success, EOF(-1) if failed.  
- freopen  
  - perpose: Reuses stream to either open the file specified by filename or to change its access mode.  
  - syntax: `FILE * freopen ( const char * filename, const char * mode, FILE * stream );`  
  - return: NULL if failed, FILE pointer if succes.  
- setvbuf  
  - perpose: Specifies an array `buffer` for stream. The function allows to specify the mode and size of the buffer (in bytes).  
  - This function should be called once the stream has been associated with an open file, but before any input or output operation is performed with it.  
  - syntax: `int setvbuf ( FILE * stream, char * buffer, int mode, size_t size );`  
  - buffer: input 'NULL' if you want system auto manage buffer.
  - mode: Specifies a mode for file buffering. Three special macro constants (_IOFBF, _IOLBF and _IONBF) are defined. Read here: https://cplusplus.com/reference/cstdio/setvbuf/  
  - return: 0 if succes, !0 if failed

- setbuf
  - perpose: 
  - syntax: `void setbuf ( FILE * stream, char * buffer );`   


- fflush  
  - perpose: Only using it to flush out stream. shouldn't using fflush(stdin), it may do something unexpected, then 'scanf' can wrong process.  
  - syntax: `int fflush ( FILE * ostream );`
  - with 'stdin' to delete \n: using
  ``` Cpp
  // to input string
  scanf("%[\n]%*c");

  // to input a character then 'fgetc' to clear '\n'
  // but you should handle input case '\n' because 'fgetc' can stop if stdin empty, it will not return EOF
  getchar();

  // other case we use 'fgetc' to clear '\n' after input
  ```


3. Format I/O
-  Note:
  - functions have prefix (f-) like: fprintf, fscanf, ... using i/o with stream, which get data bytes input after format (UTF8, UTF16, ..., binary) from key board or stream and redirect to another stream.
    - These functions are suitable for handling file reading and writing, and display processing.
  - functions have prefix (f-) like: sprintf, sscanf,... using i/o with buffer (string, array, buffer), which get data bytes input after format (UTF8, UTF16, ..., binary) from key board or stream and redirect to another buffer.
    - These functions are suitable for handling buffer data on RAM.

4. I/O with stream
5. I/O block data
6. File position
7. Error handling
