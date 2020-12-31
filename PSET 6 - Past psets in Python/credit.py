from cs50 import get_int
import math

#Get the credit card number
number = get_int("Number: ")
while(number <= 0 or number >= 10e16):
    number = get_int("Number: ")
    if(number < 4e12 or number > 56e14):
        print("INVALID")
        break

#Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
sum1 = 0
n_digits = 0
counting = number
number_card = number

while(counting != 0):
    counting = counting // 10
    n_digits = n_digits + 1

while (n_digits > 0):
    every_other_digit = (number_card % 100) // 10
    multiply_by_2 = every_other_digit * 2
    if (multiply_by_2 >= 5):
        multiply_by_2 = (multiply_by_2 // 10) + (multiply_by_2 % 10)
    sum1 = sum1 + multiply_by_2
    every_other_digit = 0
    multiply_by_2 = 0
    number_card = number_card // 100
    n_digits = n_digits - 1

#Add the sum to the sum of the digits that weren’t multiplied by 2.
sum2 = number % 10
n_digits2 = 0
counting2 = number // 10
number_card2 = number // 10

while(counting2 != 0):
    counting2 = counting2 // 10
    n_digits2 = n_digits2 + 1

while (n_digits2 > 0):
    other_digit = (number_card2 % 100) // 10
    sum2 = sum2 + other_digit
    other_digit = 0
    number_card2 = number_card2 // 100
    n_digits2 = n_digits2 - 1

sumtotal = sum1 + sum2
digit1 = 0
digit2 = 0
num_digits = 0
while number > 0:
    digit2 = digit1
    digit1 = number % 10
    number = number // 10
    num_digits = num_digits + 1
    
first_two_digits = (digit1*10) + digit2

#If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
if ((sumtotal % 10) != 0 ):
    print("INVALID")
#Print what type of card
else:
    if (first_two_digits == 34 or first_two_digits == 37) and num_digits == 15:
        print("AMEX")
    elif (first_two_digits >= 51 and first_two_digits <= 55) and num_digits == 16:
        print("MASTERCARD")
    elif digit1 == 4 and (num_digits >= 13 and num_digits <= 16):
        print("VISA")
    else:
        print("INVALID")