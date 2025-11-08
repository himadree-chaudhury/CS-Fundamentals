#include<stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
 int count_for_two = 0;
 int count_for_three = 0;
 for (int i = 0; i < N;i++){
    if(arr[i] % 2 == 0 && arr[i] % 3 == 0){
        count_for_two++;
    }
    else if(arr[i] % 2 == 0){
        count_for_two++;
    }
    else if(arr[i] % 3 == 0){
        count_for_three++;
    }
 }

 printf("%d %d", count_for_two, count_for_three);

     return 0;
}