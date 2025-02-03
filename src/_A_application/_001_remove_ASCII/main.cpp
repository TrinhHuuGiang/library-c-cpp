/*
Remove ASCII:
- A program to monitor ASCII characters in a text file.
- Remove some ASCII characters user input.

Copyright (C) 2025  Giang Trinh.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

/***************************************
Definitions
***************************************/
#include "main_state.h"

/***************************************
Code
***************************************/

/**
 * @brief main fuction
 * 
 * @return
 * 0 - no problem
 * 
 * not 0 - call menu for more inform
 */
int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        fprintf(stderr,"\n INPUT NOTHING \n");
        fprintf(stderr,"Syntax: ./run_app.out [link to text file]\n");
        return 1;
    }

    // if input menu -> menu
    // if input sonething else -> check


    if(driver_remove_ASCII(argv[1]))
    {
        return 2;
    }

    // anything ok
    fprintf(stderr,"\n EXIT OKEY \n");
    return 0;    
}
