#include<stdio.h>
int main() {

    char S[10000];
    scanf("%s", S);

    int letter_number[26] = {0};
    for(int i = 0; S[i] != '\0'; i++) {
        scanf("%d", &letter_number[i]);
    }
    
    for(int i = 0; S[i] != '\0'; i++) {
        int value = S[i];
        int position = value - 'a';
        letter_number[position] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if(letter_number[i] > 0) {
            char ch = 'a' + i;
            printf("%c - %d\n", ch, letter_number[i]);
        }
    }
    
    return 0;
}