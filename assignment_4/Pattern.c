#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {

        for(int k=1; k<=N-i; k++)
        {
            printf(" ");
        }

        if (i % 2 == 0)
        {
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                printf("-");
            }
        }
        else
        {
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                printf("#");
            }
        }
        printf("\n");
    }
    for (int i = N; i >= 1; i--)
    {

        for (int k = N; k >= i; k--)
        {
            printf(" ");
        }

        if (i % 2 != 0)
        {
            for (int j = 1; j <= 2 * i - 3; j++)
            {
                printf("-");
            }
        }
        else
        {
            for (int j = 1; j <= 2 * i - 3; j++)
            {
                printf("#");
            }
        }

        printf("\n");
    }

    return 0;
}
