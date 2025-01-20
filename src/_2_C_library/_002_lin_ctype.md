# content
- [library cctype / ctype.h](#library-cctype-or-ctypeh)

<hr>

# Library cctype or ctype.h
- Function:  
1. Classification set functions:  
    1. isalnum  
        - purpose: check input individual charactor 'c' is alphabet or number  
        - syntax:  
            ```Cpp
            int isalnum ( int c ); // c has to ASCII value
            ```
        - return:  
            0 is false  
            !0 is 'a-z', 'A-Z', '0-9'  

    2. isalpha  == a-z, A-Z  
    3. isdigit  == 0-9  
    4. isxdigit == hexanumber(0-9, a-f, A-F)  
    5. ispunct  == ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ \` { }  
    6. isspace  == space, tab, newline, carriage return, form feed, vertical tab  
    7. isblank  == space, tab  
    8. islower  == a-z  
    9. isupper  == A-Z  
    10. iscntrl == ASCII 0-31, 127  
    11. isprint == printing characters are all with an ASCII code greater than 0x1f (US), except 0x7f (DEL).  
    12. isgraph == like isprint but except ' ' character   

2. Conversion functions  
    1. tolower   
    2. toupper   

