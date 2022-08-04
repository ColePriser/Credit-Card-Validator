#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

//6011111111111117 valid example (13 1's)

void validate(long long cred_num, int length) {
    int check_sum = 0;
    long long manipulate_num = cred_num;

    //Use Luhn's Alrogithm
    for (int x = 1; x < length + 1; x++) {

        //Isolates the current digit we are looking at
        int cur_digit = manipulate_num % 10LL;

        //Every other digit is multiplied by 2
        if (x % 2 == 0) {
            cur_digit *= 2;

            //If digit is double digit after multiplying by 2, then subtract 9 from it
            if (cur_digit >= 10) {
                cur_digit -= 9;
            }
        }

        //Add current digit we have been editing to the check sum
        check_sum += cur_digit;

        //Remove digit we just used from ongoing calculations
        manipulate_num /= 10LL;
    }

    //If the check sum divided by 10 has a remainder of 0, then this credit card number is valid
    if (check_sum % 10 == 0) {
        printf("Valid Number!\n", check_sum);
    } 
    else {
        printf("Invalid Number!\n", check_sum);
    }
}

void company(long long cred_num, int length) {
    //Find first digit of inputted credit card number
    int first_dig = cred_num;
    while (first_dig > 10LL) {
        first_dig /= 10LL;
    }

    //Using the first_dig to see company
    //American Express numbers start with 3
    //Visa numbers start with 4
    //MasterCard numbers start with 5
    //Discover numbers start with 6
    //Everything else is unknown to this program
    if (first_dig == 3) {
        printf("Company: American Express\n");
    } else if (first_dig == 4) {
        printf("Company: Visa\n");
    } else if (first_dig == 5) {
        printf("Company: MasterCard\n");
    } else if (first_dig == 6) {
        printf("Company: Discover\n");
    } else {
        printf("Company: UNKNOWN\n");
    }
}

int main() {   
    bool again = false;
    do {
        long long cred_num = 0LL;

        //Initial credit card input request
        printf("Input your credit card number below (NO SPACES):\n");
        
        //Ensure number is in given range
        do {
            scanf("%lld", &cred_num);
        } while (cred_num < 1LL || cred_num > 9999999999999999LL);

        //Count the length of inputted number using variable 'length'
        int length = 0;
        long long manipulate_num = cred_num;
        while (manipulate_num > 0LL) {
            manipulate_num /= 10LL;
            length++;
        }
        
        //Only checking certain companies with the given credit card number lengths
        if (length != 13 && length != 15 && length != 16 && length != 19) {
            printf("Invalid number of digits.\n");
        } else {
            //Call company function to check where credit card belongs
            company(cred_num, length);

            //Call validate function to see if number is valid
            validate(cred_num, length);
        }

        //Ask user if they want to check another card
        printf("Type YES if you want to input a new credit card number:\n");
        char *input = malloc(4);
        scanf("%s", input);
        if (strcmp(input, "YES") == 0) {
            again = true;
        } else {
            again = false;
        }
    } while (again);
    return 0;
}