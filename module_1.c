#include <stdio.h>      // Standard input-output header file
#include <stdbool.h>    // Header file for boolean type

int main() {
    int num=10;
    char ch = 'A';
    float f = 3.14;
    bool isTrue = true;
    int input;



    printf("Hello, World!\n");
    printf("The value of num is: %d\n", num);
    printf("The value of ch is: %c\n", ch);
    printf("The value of f is: %.2f\n", f);
    printf("The value of isTrue is: %d\n", isTrue);
    scanf("%d", &input);
    printf("You entered: %d\n", input);
    return 0;
}



    /*
    %d - format specifier for integers
    %c - format specifier for characters
    %f - format specifier for floating-point numbers
    %.2f - format specifier for floating-point numbers with 2 decimal places
    %s - format specifier for strings
    %lld - format specifier for long long integers
    %lf - format specifier for double precision floating-point numbers 
    & - address-of operator, used to get the address of a variable & updates the variable value in scanf function
    \n - newline character, used to move to the next line in output
    \t - tab character, used to add a horizontal tab space in output

    int : 4 bytes (32 bits, 2^32 range = 4*10^9(Can store up to 4 billion))
    long long: 8 bytes (64 bits, 2^64 range = 16*10^18(Can store up to 16 quintillion))
    float : 4 bytes (Can store up to 7 decimal digits or with decimal about 7-8 digits)
    double : 8 bytes (Can store up to 15 decimal digits or with decimal about 16-17 digits)
    char : 1 byte (8 bits, 2^8 range = 256(Can store up to 256 characters))

    garbage value - A variable that has not been initialized may contain any random value. e.g., int x; printf("%d", x); // x may contain a garbage value

    *variable name only contains letters, digits and underscore(_)
    *variable name should not start with a digit or special character
    *variable name should not be a keyword (e.g., int, return, if, else, while, for, etc.)


    %To get character to number conversion: use ASCII values
    '0' to '9' : 48 to 57
    'A' to 'Z' : 65 to 90
    'a' to 'z' : 97 to 122

    Example: char ch = '5';
             int num = ch - '0'; // num will be 5
             printf("%d\n", num);
             printf("%c\n", num + '0'); // prints '5'
             printf("%d\n", '5' - '0'); // prints 5
             printf("%d\n", 'A'); // prints 65
             printf("%c\n", 'A'); // prints 'A'
             printf("%d\n", 'A' - '0'); // prints 65
             printf("%d\n", 'a' - '0'); // prints 97


    */ 