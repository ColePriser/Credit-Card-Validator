#include <stdio.h>

int main() {
    long credNum;
    printf("Input your credit card number below:\n");
    scanf("%ld\n", &credNum);

    //Keeps asking for new card number until it is greater than 0
    while (credNum <= 0) {
        printf("Invalid number! Try again:\n");
        scanf("%ld\n", &credNum);
    }

    return 0;
}