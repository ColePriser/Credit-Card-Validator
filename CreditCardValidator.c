/** 
    Checks whether a credit card number is valid by using Luhn's Alrogithm.
    Also displays what type of card this is (such as MasterCard). 
    @file CreditCardValidator.c
    @author Cole Priser
    @version 1.1 8/8/2022
*/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This function checks if a credit card number (CCN) is valid according to Luhn's Alrogithm.
 * @param cred_num  The CCN that the user inputs
 * @param length The number of digits in the CCN
 * @return true If CCN valid
 * @return false If card CCN valid
 */

bool validate(long long cred_num, int length) {
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

    //If the check sum divided by 10 has a remainder of 0, then this credit card number is valid and we return true
    if (check_sum % 10 == 0) {
        printf("Valid Number!\n", check_sum);
        return true;
    }
    //Otherwise, credit card number is invalid and we return false
    printf("Invalid Number!\n", check_sum);
    return false;
}

/**
 * @brief This function checks the card type based off the first digit of the CCN.
 * 
 * @param cred_num The CCN that the user inputs
 */
void check_card_type(long long cred_num) {
    //Find the industry number of credit card, which is the very first number
    int count = log10(cred_num);
    int first_dig = cred_num / pow(10, count);

    //If first digit number is 1, then it is an Airline card
    if (first_dig == 1) {
        printf("Card Type: Airline\n");
    }
    //If first digit number is 2, then it is a MasterCard card
    else if (first_dig == 2) {
        printf("Card Type: MasterCard\n");
    } 
    //If first digit number is 3, then it is an American Express or Diners Club card
    else if (first_dig == 3) {
        printf("Card Type: American Express or Diners Club\n");
    } 
    //If first digit number is 4, then it is a Visa card
    else if (first_dig == 4) {
        printf("Card Type: Visa\n");
    } 
    //If first digit number is 5, then it is a MasterCard card
    else if (first_dig == 5) {
        printf("Card Type: MasterCard\n");
    } 
    //If first digit number is 6, then it is a Discover card
    else if (first_dig == 6) {
        printf("Card Type: Discover\n");
    } 
    //If first digit number is 7, then it is a Petroleum card
    else if (first_dig == 7) {
        printf("Card Type: Petroleum\n");
    } 
    //If first digit number is 8, then it is a Telecommunications card
    else if (first_dig == 8) {
        printf("Card Type: Telecommunications\n");
    } 
    //If first digit number is 9, then it is a Government card
    else if (first_dig == 9) {
        printf("Card Type: Government\n");
    } 
    //If industry number is anything else, then it is unknown to this program.
    else {
        printf("Card Type: UNKNOWN\n");
    }
}

/**
 * @brief Controls the operation of the program.
 */
int main() {   
    bool again = false;
    do {
        long long cred_num = 0LL;

        //Initial credit card input request
        printf("Input your credit card number below (NO SPACES and 13-16 digits long):\n");
        scanf("%lld", &cred_num);
        
        //Ensure number is greater than 12 digits and less than 17 digits
        if (cred_num < 999999999999LL || cred_num > 9999999999999999LL) {
            printf("Invalid number of digits (must be 13-16 digits long).\n");
        } else {
            //Count the length of inputted number using variable 'length'
            int length = 0;
            long long manipulate_num = cred_num;
            while (manipulate_num > 0LL) {
                manipulate_num /= 10LL;
                length++;
            }

            //Call validate function to see if number is valid
            bool val = validate(cred_num, length);

            //If credit card number is valid, then we will check what company it belongs to
            if (val) {
                check_card_type(cred_num);
            }
        }

        //Ask user if they want to check another card
        printf("Type 'YES' if you want to input a new credit card number. Otherwise, type anything else:\n");
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