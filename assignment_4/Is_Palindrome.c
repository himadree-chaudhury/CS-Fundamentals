#include <stdio.h>
#include <string.h>

int is_palindrome(char S[])
{
    int count = strlen(S);
    char reverse[1000];

    for (int i = count - 1; i >= 0; i--)
    {
        reverse[count - i - 1] = S[i];
    }
    reverse[count] = '\0';

    if (strcmp(S,reverse)==0)
    {

        return 1;
    }
    else
    {

        return 0;
    }
}

int main()
{
    char S[1000];
    scanf("%s", &S);

    const result = is_palindrome(S);
    if (result==1)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }

    return 0;
}