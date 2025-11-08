#include<stdio.h>
int main() {
    char str[100000];
    scanf("%s", str);

    int constant_count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            constant_count++;
        }
    }

    printf("%d", constant_count);

    return 0;
}