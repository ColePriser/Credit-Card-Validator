# Credit-Card-Validator

This Credit Card Validator uses the Luhn Algorithm to verify a given credit card number (CCN).
Luhn is used with MasterCard, American Express, Visa, Discover, and more major credit cards.
This program requires the user to input a CCN that is 13 through 16 digits long.

This program will also display what type of card this is based on the first digit of the CCN:


| First Number  | Card Type |
| ------------- | ------------- |
| 1  | Airline  |
| 2  | MasterCard  |
| 3  | American Express or Diners Club  |
| 4  | Visa  |
| 5  | MasterCard  |
| 6  | Discover  |
| 7  | Petroleum  |
| 8  | Telecommunications  |
| 9  | Government  |


## Luhn's Alrogithm:

This is a simple checksum formula that is used to validate credit card numbers. 

Step 1:
Starting at the leftmost digit, double the value of every second digit (odd indexes if first digit is index 1).

Step 2:
If doubling a digit results in a double digit number, then subtract this double digit by 9.

Step 3:
Add the current digit that we have been editing to the check sum (start at sum of 0).

Step 4:
If the final check sum is divisible by 10 (last number is 0), then this CCN is valid. Otherwise, the CCN is invalid.
