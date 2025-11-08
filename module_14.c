#include <stdio.h>
#include <math.h>

// Scopes of Variables
// 1. Global Scope: Accessible throughout the program, e.g., global variables like below
int global_var = 100; // declared outside any function
// 2. File Scope: Accessible within the file, e.g., static global variables
static int file_var = 200; // declared with static keyword
// 3. Function Scope: Accessible within the function, e.g., function parameters
// 4. Block Scope: Accessible within the block, e.g., within loops or conditionals or braces {}

// User Defined Function Types
// 1. Functions without arguments and without return value
void greet()
{
    printf("1. inside without args without return\n");
    printf("The sum is:");

    // return; can be used to exit the function early but can not be used to return a value
}

// 2. Functions with arguments and without return value
void printResult(int sum) // void indicates no return value
{
    printf("2. inside with args without return\n");
    greet();
    printf(" %d\n", sum);
}

// 3. Functions without arguments and with return value
int takeInput()
{
    int num;
    scanf("%d", &num);
    printf("3. inside without args with return\n");
    return num;
}

// 4. Functions with arguments and with return value
int sum(int a, int b)
{
    printf("4. inside with args with return\n");
    return a + b;
}

int main()
{
    int result = sum(takeInput(), takeInput());
    printResult(result);

    // Useful built-in mathematical functions
    int ans = ceil(4.3); // rounds up to the nearest integer
    printf("The ceiling of 4.3 is: %d\n", ans);

    ans = floor(4.7); // rounds down to the nearest integer
    printf("The floor of 4.7 is: %d\n", ans);

    ans = round(4.3); // rounds to the nearest integer
    printf("The rounded value of 4.3 is: %d\n", ans);

    ans = sqrt(16); // square root
    printf("The square root of 16 is: %d\n", ans);

    ans = pow(2, 3); // power function
    printf("The result of 2 raised to the power of 3 is: %d\n", ans);

    ans = abs(-10); // absolute value
    printf("The absolute value of -10 is: %d\n", ans);

    return 0;
    // Why return 0?
    // The operating system uses the return value of the main function to determine if the program executed successfully or if there were errors. In C the value 0 typically indicates successful execution, while non-zero values indicate different types of errors.
}