#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

//6011111111111117 valid example (13 1's)

int getDigitByIndex(int num, int index) {
    int digit = num / pow(10, index);
    return digit % 10;
}

void validate(long long int credCardNum) {
    int checkSum = 0;

    //Find length of credit card number
    int length = floor(log10(abs(credCardNum))) + 1;
    for (int x = length; x >= 0; x--) {
        //Find check sum of odd indexes
        if (x % 2 == 1) {
            //Just add every number at odd index
            checkSum += getDigitByIndex(credCardNum, x);
        } 
        //Find check sum of even indexes
        else {
            //Double every number at even index
            int doubleNum = 2 * getDigitByIndex(credCardNum, x);

            //If doubleNum is double digit, then subtract 9 and add to check sum.
            if (doubleNum > 9) {
                doubleNum -= 9;
                checkSum += doubleNum;
            } else {
                //If this double is single digit, then add it to the check sum.
                checkSum += doubleNum;
            }
        }
    }

    //If the check sum divided by 10 has a remainder of 0, then this credit card number is valid
    if (checkSum % 10 == 0) {
        printf("Valid Number!\n");
    } else {
        printf("Invalid Number!\n");
    }
}

int main() {   
    bool goAgain = false;
    do {
        long long int credNum;
    
        //Initial credit card input request
        printf("Input your credit card number below (NO SPACES):\n");
        scanf("%lli", &credNum);
        printf("you put %lli\n", credNum);

        //Call validate function to see if number is valid
        validate(credNum);
        printf("Type YES if you want to input a new credit card number:\n");
        char *again = malloc(4);
        scanf("%s", again);
        if (strcmp(again, "YES") == 0) {
            goAgain = true;
        } else {
            goAgain = false;
        }
    } while (goAgain);
    return 0;
}