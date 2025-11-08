#include <stdio.h>

int main()
{

    // Sum of two variable is equal to a specific value

    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target_sum;
    int flag = 0;       // to check if pair found or not
    scanf("%d", &target_sum);

    for (int i = 0; i <= N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] + arr[j] == target_sum)
            {
                flag = 1;
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
            }
        }
    }

    if (flag == 0)
    {
        printf("No pair found\n");
    }


    // Sorting an array using Selection Sort

    // Ascending Order
    for (int i = 0; i < N - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_index])        // Check if the current element is smaller than the minimum found so far
            {
                min_index = j;
            }
        }
        // Swap arr[i] and arr[min_index]
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }

    // Descending Order
    for( int i = 0; i < N - 1; i++){
        int max_index = i;
        for( int j = i + 1; j < N; j++){
            if( arr[j] > arr[max_index]){
                max_index = j;
            }
        }
        // Swap arr[i] and arr[max_index]
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }

    printf("\nSorted array in Descending Order: ");
    for( int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
        return 0;
}