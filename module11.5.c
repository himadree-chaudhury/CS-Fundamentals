#include <stdio.h>
#include <string.h>
int main(){

    // Counting/Frequency array: Count frequency or occurrence of each character in a string.

    int N;
    scanf("%d", &N);
    int arr[N];

    for(int i=0; i<N; i++){
     scanf("%d", &arr[i]);
    }

    // Count frequency of each character
    int freq[256] = {0}; // Assuming ASCII character set
    for(int i=0; i<N; i++){
        freq[arr[i]]++;
    }

    // Print frequency of each character
    for(int i=0; i<256; i++){
        if(freq[i] > 0){
            printf("Number %d occurs %d times\n", i, freq[i]);
        }
    }

    return 0;
}