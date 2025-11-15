#include <stdio.h>
// Call stack: The memory that keeps track of function calls. It works like a LIFO (Last In, First Out) structure.
// Recursion: A function(Recursive function) that calls itself. A question arise: isn't it infinite? No, because of the base case. Otherwise it would be cause a stack overflow.
// Base case: The condition under which a recursive function stops calling itself.

void recursive_function(int count)
{
    if (count >= 6) // Base case
    {
        return;
    }
    printf("Count: %d\n", count);   // Print before the recursive call: Ascending
    recursive_function(count + 1); // Recursive call
    printf("Count: %d\n", count);   // Print after the recursive call: Descending
}

void recursive_array_function(int arr[], int size, int index)
{
    if (index >= size) // Base case
    {
        return;
    }
    printf("Array Element [%d]: %d\n", index, arr[index]); // Print before the recursive call: Ascending
    recursive_array_function(arr, size, index + 1);       // Recursive call
    printf("Array Element [%d]: %d\n", index, arr[index]); // Print after the recursive call: Descending
}   

int main()
{
    recursive_function(1);

    printf("------------------------\n");

    // Recursion on an array
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    recursive_array_function(arr, N, 0);
    return 0;
}