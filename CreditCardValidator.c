#include <stdio.h>

int main() {
    long credNum;
    printf("Input your credit card number!\n");
    scanf("%ld\n", &credNum);
    while (credNum <= 0) {
        printf("Invalid number! Try again!\n");
        scanf("%ld\n", &credNum);
    }
    
    return 0;
}