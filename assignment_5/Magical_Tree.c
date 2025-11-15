#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= 5 + ((N + 1) / 2); i++)
    {
        for (int j = (5 + ((N + 1) / 2)) - i; j >= 1; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 5; j >= 1; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= N; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}