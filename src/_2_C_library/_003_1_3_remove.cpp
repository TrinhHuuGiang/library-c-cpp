// add execute mode: chmod +x ./_003_1_0_file_handling.sh
// run script: ./_003_1_0_file_handling.sh

// using POSIX API to read folder in library <dirent.h>
// this program open input link folder and read all items in it.
// then user will chose one to rename

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <dirent.h>
#include <string.h>

using namespace std;

typedef struct dirent dirent;


int main(int argc, char* argv[])
{
    // variable
    DIR* dir = NULL;
    dirent* entry = NULL;

    // check argc > 1, user input some link
    if(argc <= 1)
    {
        // user input nothing
        fprintf(stderr, "\n[Nothing] User input nothing.\n");
        return 1;
    }

    // open directory user input
    dir = opendir(argv[1]);
    if(dir == NULL)
    {
        perror("opendir");//print errno properties
        return 2;
    }

    // read file/ folder
    // ignore default folder ../ and ./
    cerr<<"\n==========\nfolder: "<<argv[1]<<endl;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            cerr << "Name: " << entry->d_name << ", Inode: " << entry->d_ino << endl;
        }
    }  

    // input file name want to delete
    {
        char* str_file = (char*)calloc(256, sizeof(char));

        cerr<<endl<<"Input file want to delete: ";
        scanf("%[^\n]%*c", str_file);

        // check file name length ok
        if(str_file[255] != 0)
        {
            fprintf(stderr, "[Err] - input out of range !!\n");

            free(str_file);
            closedir(dir);
            return 3;
        }

        // link folder with file name
        {
            char* link_file = (char*)calloc(256*2, sizeof(char));
            //link with argv[1]
            strcat(link_file,argv[1]);
            //link with name
            strcat(link_file,str_file);

            // delete
            if(remove(link_file))
            {
                perror("[Err] - delete failed");

                free(str_file);
                free(link_file);
                closedir(dir);
                return 4;
            }
            
            // free 
            free(str_file);
            free(link_file);
        }
    }

    // read file/ folder again
    // ignore default folder ../ and ./
    cerr<<"\n==========\nfolder: "<<argv[1]<<endl;
    rewinddir(dir);
    while ((entry = readdir(dir)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            cerr << "Name: " << entry->d_name << ", Inode: " << entry->d_ino << endl;
        }
    }  

    //exit
    closedir(dir);
    //note that 'entry' don't need free, because it only refer to component of 'dir'
    return 0;
}