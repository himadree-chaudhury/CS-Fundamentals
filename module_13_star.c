#include <stdio.h>

int main()
{

    int N;
    scanf("%d", &N);

    // Upward Left Triangle
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Downward Left Triangle
    for (int i = N; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Upward Right Triangle
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= N - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Downward Right Triangle
    for (int i = N; i > 0; i--)
    {
        for (int k = 1; k <= N - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Upward Pyramid
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= N - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Downward Pyramid
    for (int i = N; i > 0; i--)
    {
        for (int k = 1; k <= N - i; k++)
        {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}