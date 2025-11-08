#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    // data_type array_name[array_size];
    int arr[n]; // Array of size n

    // Initialization of array elements in declaration (This only works for fixed size arrays not variable length arrays like arr[n])
    // int arr[] = {value1, value2, value3, ..., valueN};
    // int arr[5] = {1, 2, 3, 4, 5};
    // int arr[5] = {0}; // All elements initialized to 0
    // int arr[5] = {1}; // First element initialized to 1, other elements to 0

    // Initialization of the array
    // arr[0] = value;

    // Accessing and printing array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Taking input for each element
    }

    for(int i = 0; i < n; i++) {
        printf("Element at index %d: %d\n", i, arr[i]); // Printing each element
    }

    printf("\n");

    // Printing array elements in reverse order
    for(int i = n-1; i >= 0; i--) {
        printf("Element at index %d: %d\n", i, arr[i]); // Printing each element
    }

    return 0;
}