#include <stdio.h>
#include <string.h>

int main(){
    // String: Array of characters
    // int n;
    // scanf("%d", &n);
    // char str[n+1]; // +1 for null terminator
    char str[19] = "Himu";

    // '\0' indicates the end of the string and is automatically added after the last character when using %s format specifier. It interprets as null which ascii value 0.

    // scanf("%s", str); // Input string, Can be taken input by loop using %c format specifier as well

    // The scanf with %s stops taking input after encountering a whitespace character (space, tab, newline). So it reads a single word.To read a full line with spaces, use gets() or fgets() instead.
    fgets(str, sizeof(str), stdin);    // gets() is unsafe and deprecated, use fgets() instead. (string, sizeof(str) gives the size of the array including the null terminator, standard input stream is stdin)
    // fgets() reads until a newline character is encountered or the specified limit is reached, whichever comes first. It also includes the newline character in the string if there's enough space.So if the string has a space use fgets() to read the full line and if multiple lines with no space needed use scanf.


    printf("%s\n", str); // Print the string
    printf("%c\n", str[0]); // Print the first character of the string

    // Finding the length of the string
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    // for(int i = 0; str[i] != '\0'; i++){
    //     length++;
    // }

    // Also can do this strlen(str) by including string.h library

    printf("Length of the string: %d\n", strlen(str));

    return 0;
}