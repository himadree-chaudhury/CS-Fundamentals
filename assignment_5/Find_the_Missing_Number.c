#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++)
    {
        long long int M;
        int A, B, C;
        scanf("%lld %d %d %d", &M, &A, &B, &C);
        long long int multiplication = A * B * C;
        if (multiplication == 0)
        {
            if (M == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("-1\n");
            }
        }
        else if (M % multiplication == 0)
        {
            long long int result = M / multiplication;
            printf("%lld\n", result);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}