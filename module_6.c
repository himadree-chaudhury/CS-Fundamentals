// EOF : End Of File 
// In C, the end of a file is indicated by the EOF macro defined in stdio.h.
// It is used to signal the end of input or output operations when reading from or writing to a file or standard input/output streams.


#include <stdio.h>
int main() {
    int password;
    while(scanf("%d", &password) != EOF) {
        // Here EOF indicates the end of input
        // The loop will continue until there is no more input
        if(password == 1234) {
            printf("Correct Password\n");
        } else {
            printf("Wrong Password\n");
        }
    }

    // By For Loop
    for (;scanf("%d", &password) != EOF;) {
        // No need to initialize or increment in for loop
        if(password == 1234) {
            printf("Correct Password\n");
        } else {
            printf("Wrong Password\n");
        }
    }
}

// INT_MIN and INT_MAX are constants defined in the limits.h header file in C.
// They represent the minimum and maximum values that can be stored in a variable of type int, respectively.
// includes limits.h to use INT_MIN and INT_MAX