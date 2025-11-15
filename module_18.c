#include <stdio.h>

int main()
{

    int row, col;
    scanf("%d %d", &row, &col);

    // 2D Array:
    int matrix[row][col];

    // Matrix Type Check
    if (row == 1)
    {
        printf("This is a row matrix.\n");
    }
    else if (col == 1)
    {
        printf("This is a column matrix.\n");
    }
    else if (row == col)
    {
        printf("This is a square matrix.\n");
    }

    // Matrix Input
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Zero Matrix Check
    int total_elements = row * col;
    int zero_count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                zero_count++;
            }
        }
    }

    if (zero_count == total_elements)
    {
        printf("This is a zero matrix.\n");
    }

    // Check if it is a primary diagonal matrix
    int diagonal_count = 0;
    if (row == col){
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i != j && matrix[i][j] == 0)
                {
                    diagonal_count++;
                }
            }
        }
        int non_diagonal_elements = total_elements - row; // non-diagonal elements count
        if (diagonal_count == non_diagonal_elements)
        {
            printf("This is a diagonal matrix.\n");
        }
    }

    // Full Matrix Print
    printf("The Matrix is:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Secific Row Print
    int r;
    scanf("%d", &r);
    printf("The %d th row is:\t", r);
    for (int j = 0; j < col; j++)
    {
        printf("%d ", matrix[r][j]);
    }

    // Specific Column Print
    int c;
    scanf("%d", &c);
    printf("\nThe %d th column is:\n", c);
    for (int i = 0; i < row; i++)
    {
        printf("%d\n", matrix[i][c]);
    }

    return 0;
}
