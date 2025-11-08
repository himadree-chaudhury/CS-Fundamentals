#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    char str1[1000], str2[1000];
    scanf("%s %s", str1, str2);
    
    // 1. Concatenate two strings: Use loop or strcat function. strcat is in string.h. strcat(dest, src);

    strcat(str1, str2);
    printf("After concatenation, str1: %s\n", str1);

    // 2. Copy one string to another string: Use loop or strcpy function. strcpy is in string.h. strcpy(dest, src);

    strcpy(str2, str1);
    printf("After copying, str2: %s\n", str2);



    // Lexicographical comparison of two strings: The comparison can be done by alphabetical order. That is, 'a' < 'b' < 'c' ... < 'z'. Use loop or strcmp function. strcmp is in string.h. strcmp(str1, str2);
    // 1. End of String: Compare the lengths of both strings.
        // i. str1 end: str1 is smaller
        // ii. str2 end: str2 is smaller
        // iii. str1 & str2 end: str1 == str2
    // 2. Has Character: Compare character by character.
        // i. str1 small: str1 is smaller
        // ii. str2 small: str2 is smaller
        // iii. str1 == str2: continue checking next character


    int i=0;
    while (true)    // Infinite loop or while(1)
    {
        if (str1[i] == '\0' && str2[i] == '\0')
        {
            printf("Strings are equal\n");
            break;
        }
        else if (str1[i] == '\0')
        {
            printf("str1 is smaller\n");
            break;
        }
        else if (str2[i] == '\0')
        {
            printf("str2 is smaller\n");
            break;
        }
        else if (str1[i] < str2[i])
        {
            printf("str1 is smaller\n");
            break;
        }
        else if (str1[i] > str2[i])
        {
            printf("str2 is smaller\n");
            break;
        }
        else if(str1[i] == str2[i])
        {
            i++;
        }
        
    }

    int result = strcmp(str1, str2); // returns <0 (negative value) if str1<str2, 0 if str1==str2, >0 (positive value) if str1>str2
    if (result < 0)
    {
        printf("str1 is smaller\n");
    }
    else if (result > 0)
    {
        printf("str2 is smaller\n");
    }
    else
    {
        printf("Strings are equal\n");
    }

    return 0;
}