#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

void validate(char *credCardNum) {
    int checkSum = 0;
    int length = strlen(credCardNum);
    for (int x = length - 1; x >= 0; x--) {
        //Find check sum of odd indexes
        if (x % 2 == 1) {
            //Just add every number at odd index
            checkSum += (int) credCardNum[x];
        } 
        //Find check sum of even indexes
        else {
            //Double every number at even index
            int doubleNum = 2 * (int) credCardNum[x];

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
        char *credNum= malloc(16);

        //Initial credit card input request
        printf("Input your credit card number below (NO SPACES):\n");
        scanf("%s\n", credNum);
    
        //Call validate function to see if number is valid
        validate(credNum);
        printf("validated...\n");
        bool correctInput = false;
        do {
            printf("Do you want to input a new credit card number?\n");
            printf("Type YES or NO:\n");
            char *again = malloc(4);
            scanf("%s", again);
            if (strcmp(again, "YES") == 0) {
                goAgain = true;
                correctInput = true;
            } else if (strcmp(again, "NO") == 0) {
                correctInput = true;
            }
        } while (correctInput);
    } while (goAgain);
    return 0;
}
