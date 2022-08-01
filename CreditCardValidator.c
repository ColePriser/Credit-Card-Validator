#include <stdio.h>

int main() {
    char credNum[16];

    //Initial credit card input request
    printf("Input your credit card number below:\n");
    scanf("%s\n", &credNum);

    //Keeps asking for new card number until it is greater than 0
    while (credNum <= 0) {
        printf("Invalid number! Try again:\n");
        scanf("%ld\n", &credNum);
    }

    int checkSum = 0;

    for (int x = 0; x < 16; x++) {
        //Find check sum of odd indexes
        //Just add every number at odd index
        if (x % 2 == 1) {
            checkSum += credNum[x];
        } 
        //Find check sum of even indexes
        //Double every number at even index
        //If this double is double digit, then add the two digits together.
        //Then, add this addition to the check sum.
        //If this double is single  digit, then add it to the check sum.
        else {
        }
    }
}