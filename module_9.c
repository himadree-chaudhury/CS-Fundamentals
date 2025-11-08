#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    //  *Insert elements into an array at a specific position or index.
    int position, value;
    scanf("%d %d", &position, &value);
    
    // Shift elements to the right
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;

    printf("New element added: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //  *Delete elements from an array at a specific position or index.
    int delete_position;
    scanf("%d", &delete_position);

    // Shift elements to the left
    for (int i = delete_position; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Reduce the size of the array, but we don't actually change the array size in memory
    
    printf("Element deleted: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // *Reverse an array: Two pointer approach
    for (int i = 0, j = n; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    // int i=0, j=n;
    // while (i<j)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    //     i++;
    //     j--;
    // }
    
    printf("Reversed array: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}