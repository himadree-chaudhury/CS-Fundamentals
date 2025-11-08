#include <stdio.h>

int main() {
    int money;

    scanf("%d", &money);
    if (money >= 5000) {
        if(money >= 10000) {
            printf("I will buy a laptop.\n");
        } else {
            printf("I will buy a high-end smartphone.\n");
        }
    } else if (money >= 2000) {
        printf("I will buy a tablet.\n");
    } else if (money >= 1000) {
        printf("I will buy a mobile phone.\n");
    } else {
        printf("I will save the money.\n");
    }

    return 0;
}


/*
    * Operators
    1. Arithmetic Operators: +, -, *, /, %
    2. Relational Operators: ==, !=, >, <, >=, <= (Returns true(1) or false(0))
    3. Logical Operators: &&, ||, ! (Returns true(1) or false(0))

    * Conditional Statements
    1. if statement
    2. if-else statement
    3. switch statement
    4. nested if-else statement
*/