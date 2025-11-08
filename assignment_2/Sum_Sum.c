#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
     
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int positive_sum = 0;
    int negative_sum = 0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            positive_sum += arr[i];
        } else {
            negative_sum += arr[i];
        }
    }

    printf("%d %d", positive_sum, negative_sum);

    return 0;
}