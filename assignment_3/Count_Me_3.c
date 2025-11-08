#include<stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    char str[10000];

    for (int i = 0; i < T;i++){
    scanf("%s", str);
    int small_alp_count = 0;
    int capital_alp_count = 0;
    int digit_count = 0;

    for (int j = 0;str[j]!= '\0'; j++){
        char ch = str[j];

        if(ch>= 'a' && ch<= 'z'){
            small_alp_count++;
        }
        else if(ch>= 'A' && ch<= 'Z'){
            capital_alp_count++;
        }
        else if(ch>= '0' && ch<= '9'){
            digit_count++;
        }
    }
    printf("%d %d %d\n", capital_alp_count,small_alp_count, digit_count);
}
    return 0;
}