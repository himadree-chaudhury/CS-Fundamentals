#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    if (M != N)
    {
        printf("NO\n");
        return 0;
    }

    int matrix[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int primary_diagonal_count = 0;
    int secondary_diagonal_count = 0;
    int diagonal_place = N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == j)
            {
                if (matrix[i][j] == 1)
                {
                    primary_diagonal_count++;
                }
            }
            if ((i + j) == N - 1)
            {
                if (matrix[i][j] == 1)
                {
                    secondary_diagonal_count++;
                }
            }
            if (i != j && ((i + j) != N - 1))
            {
                if (matrix[i][j] != 0)
                {
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }

    if (primary_diagonal_count == diagonal_place && secondary_diagonal_count == diagonal_place)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}