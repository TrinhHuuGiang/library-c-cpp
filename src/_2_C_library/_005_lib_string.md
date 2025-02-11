### Library `stdlib`
Some general perposes:  
- copy, concatenate, compare, search, clear, count,... with string
- [more](https://cplusplus.com/reference/cstring/)
<hr>

### Function
- copy:
    - memcpy: `void * memcpy ( void * destination, const void * source, size_t num );`
        - copy `num` bytes of source string from source pointer location to destination pointer location.
        - note: sure that size of destination array and source array should larger than `num` bytes
        - this function very useful when read/write data with difference size like struct.
    - strcpy: `char * strcpy ( char * destination, const char * source );`
        - copy all string `source` to `destination`
        - note that size of `destination` string (include `data` and `NULL` at last) should equal `sourse` string
    - strncpy: `char * strncpy ( char * destination, const char * source, size_t num );`
        - just like strcpy but limit number char will be copied
    - memmove (safer than memcpy but slower):
        - `void * memmove ( void * destination, const void * source, size_t num );`
        - unlike `memcpy`:
            - memmove: copy data to buffer then move it to destination
            - memcpy: move data to destination
        - So if we copy data from a string to a part of that string, it maybe get overlap. when overlap, the data of `memcpy` will write onto memory locate it is reading then error will occur  

- concatenation:
    - strcat: `char * strcat ( char * destination, const char * source );`
        - conatenate `source` string with last of destination string. the `NULL` '\0' at last of `destination` string will overlap by first char of `source` string.
        - not that sure size of destination enough for both string
    - strncat: `char * strncat ( char * destination, const char * source, size_t num );`
        - like strcat but limit concatenate `num` byte of source.  

- compare:
    - memcmp: `int memcmp ( const void * ptr1, const void * ptr2, size_t num );`
        - return:
            - `0`: when all byte of 2 memory is equal
            - `> 0`: if the fist different byte of ptr1 `>` ptr2
            - `< 0`: if the fist different byte of ptr1 `<` ptr2
    - strcmp: `int strcmp ( const char * str1, const char * str2 );`
        - like memcmp but using for string
    - strcmp: `int strncmp ( const char * str1, const char * str2, size_t num );`
        - only compare n char first
    - [more](https://cplusplus.com/reference/cstring/)  

- clear, set, count:
    - memset: `void * memset ( void * ptr, int value, size_t num );`
        - set `num` bytes of string to `value`
    - count: `size_t strlen ( const char * str );`
        - return length of string ignore `\0`