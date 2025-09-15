// stdio.h is a header file which has the necessary information to include the input or output related functions in our program.
// Some examples are printf and scanf
#include <stdio.h>

// string.h is a standard header file that contains functions to manipulate strings(arrays of characters)
#include <string.h>

// stdlib.h is a header (standard library) which provives a variety of commonly used functions
// Provides memory management, conversions and process control
// Some examples are malloc(), calloc(), exit(), realloc(), abs() and atoi()
#include <stdlib.h>

// unistd.h is a header that contains several functions like rmdir(), sleep() and fork()
// Provides access to the POSIX operating system API
#include <unistd.h>

int main (int argc, char* argv[]){
    int id = fork();
    //printf("Hello World from id: %d!\n", id);
    if (id == 0){
        for (int row = 1; row < 51; i++){
            for (int column = 1; column < 1001; column++){
                int cell_val = matrix[row][column];
            }

        }
    }else{
        for (int row = 51; row < 101; i++){
            for (int column = 1; column < 1001; column++){
                int cell_val = matrix[row][column];
            }
        }
    }
    return 0;
}