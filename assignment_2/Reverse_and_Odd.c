#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    
    int arr[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if(N%2==0){
        for (int i = N-1; i >=0; i-=2) {
            printf("%d ", arr[i]);
        }
    }else{
        for (int i = N-2; i >=0; i-=2) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}