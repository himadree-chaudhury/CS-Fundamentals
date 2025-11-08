#include <stdio.h>

int main() {

    // for loop
    for(int i = 1; i <= 10; i++) {
    printf("%d ", i);   
    }
    printf("\n");

    // while loop
    int j = 1;
    while(j <= 10) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // do-while loop
    int k = 1;
    do {
        k++;
        
        if(k == 6) {
            continue; // Skip the rest of the loop when k is 6
        }
        if(k == 9) {
            break; // Exit the loop when k is 9
        }

        printf("%d ", k);
    } while(k <= 10);
    printf("\n");

    return 0;
}


// Break and Continue Statements
/*
    1. Break Statement: It is used to terminate the loop or switch statement.
    2. Continue Statement: It is used to skip the current iteration of the loop and move to the next iteration.
*/
