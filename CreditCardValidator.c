#include <stdio.h>
#include <math.h>

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

    for (int x = 15; x >= 0; x--) {
        //Find check sum of odd indexes
        if (x % 2 == 1) {
            //Just add every number at odd index
            checkSum += credNum[x];
        } 
        //Find check sum of even indexes
        else {
            //Double every number at even index
            int doubleNum = credNum[x];
            doubleNum = credNum[x] * 2;

            //If doubleNum is double digit, then add the two digits together.
            if (doubleNum > 9) {
                int firstNum = doubleNum / pow(10, log10(doubleNum));
                int lastNum = doubleNum % 10;
                int addition = firstNum + lastNum;

                //Add this addition to the check sum.
                checkSum += addition;
            } else {
                //If this double is single digit, then add it to the check sum.
                checkSum += doubleNum;
            }
        }
    }

    //If the check sum divided by 10 has a remainder of 0, then this credit card number is valid
    if (checkSum % 10 == 0) {
        printf("Valid credit card number!\n");
    }
    else {
        printf("Invlid credit card number!\n");
    }
    return 0;
}

