#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N;i++){
        for(int j=N;j>i;j--){
            printf(" ");
        }

        for (int k = i; k >= 1;k--){
            printf("%d",k);
        }

        printf("\n");
    }
        return 0;
}