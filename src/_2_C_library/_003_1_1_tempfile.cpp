// add execute mode: chmod +x ./_003_1_0_file_handling.sh
// run script: ./_003_1_0_file_handling.sh

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[])
{
    char tmp_str[256] = {0};
    char* temp_name = NULL;
    FILE* temp_ptr = NULL; 

    // [ tmpname ]
    temp_name = tempnam("./temp/", "tem_");
    if(!temp_name)
    {
        perror("Failed create temp file");
        return 1;
    }
    // check file name
    cout<<"New temp file: \""<<temp_name<<"\""<<endl;
    
    // write something into file, otherwise file auto delete by operating system
    temp_ptr = fopen(temp_name, "a+");
    if(!temp_ptr)
    {
        perror("Failed open file");
        return 2;
    }
    fprintf(temp_ptr,"Hello everyone");

    // print content were written into file
    rewind(temp_ptr);
    fscanf(temp_ptr,"%[^\n]",tmp_str);

    fprintf(stderr,"File content: %s\n", tmp_str);

    // free allocate file name + close file stream
    fclose(temp_ptr);
    free(temp_name);

    // exit
    fflush(stdin);
    getchar();
    return 0;
}