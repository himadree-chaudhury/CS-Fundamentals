#include<stdio.h>
int main() {
 
    int T;
    scanf("%d", &T);
    int M1, M2, D;
    for (int i = 0; i < T;i++){
        scanf("%d %d %d", &M1, &M2, &D);
        
        int days_to_complete = (M1*D)/(M1+M2);
        int days_reduction = D - days_to_complete;
        printf("%d\n", days_reduction);
    }

        return 0;
}