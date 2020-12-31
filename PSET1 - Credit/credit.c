/*Write a program that prompts the user for a credit card number and then reports (via printf) 
whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*Declaring the created function*/
int evens(long number_card);
int odds(long number_card);
void credit(int sum1, int sum2, long number_card);

/*Declaring the main function*/
int main(void)
{
    long credit_card = get_long("Credit card number: ");
    while (credit_card <= 0 || credit_card >= 10000000000000000)
    {
        credit_card = get_long("Credit card number: ");
    }
    if (credit_card < 4000000000000 || credit_card > 5600000000000000)
    {
        printf("INVALID\n");
    }
    else
    {
        credit(evens(credit_card),odds(credit_card), credit_card);    
    }
}

/*Specifying the created function*/
int evens(long number_card)
{
    int n_digits = 0;
    int counting = number_card;
    int sum = 0;
    int digit = 0;

    while (counting != 0)
    {
        counting = counting / 10;
        n_digits++;
    }

    while (n_digits > 0)
    {
        digit = ((number_card % 100) / 10);
        digit = digit * 2;
        if (digit >= 5)
        {
            digit = (digit / 10) + (digit % 10);
        }
        sum = sum + digit;
        n_digits--;
        digit = 0;
        number_card = number_card / 100;
    }
    return sum;
}

int odds(long number_card)
{
    int last_digit = number_card % 10;
    int n_digits = 0;
    int counting = number_card / 10;
    int sum = last_digit;
    int digit = 0;
    
    while (counting != 0)
    {
        counting = counting / 10;
        n_digits++;
    }

    number_card = number_card / 10;

    while (n_digits > 0)
    {
        digit = ((number_card % 100) / 10);
        sum = sum + digit;
        n_digits--;
        digit = 0;
        number_card = number_card / 100;
    }
    return sum;
}

void credit(int sum1, int sum2, long number_card)
{
    int sum = sum1 + sum2;
    
    int validation = sum % 10;
    
    /*If-else for the printf*/
    /*AMEX condition: card starts with 34 or 37 and uses 15-digit numbers*/
    if (floor(number_card / 340000000000000) == 1 && floor(number_card / 350000000000000) == 0 && validation == 0) 
    {
        printf("AMEX\n");
    }
    else if (floor(number_card / 370000000000000) == 1 && validation == 0)
    {
        printf("AMEX\n");
    }
    /*MASTERCARD condition: card starts with 51, 52, 53, 54 or 55 and uses 16-digit numbers*/
    else if (floor(number_card / 5100000000000000) == 1 && validation == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (floor(number_card / 5200000000000000) == 1 && validation == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (floor(number_card / 5300000000000000) == 1 && validation == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (floor(number_card / 5400000000000000) == 1 && validation == 0)
    {
        printf("MASTERCARD\n");
    }
    else if (floor(number_card / 5500000000000000) == 1 && validation == 0)
    {
        printf("MASTERCARD\n");
    }
    /*VISA condition: card starts with 40 and uses 13- and 16-digit numbers*/
    else if (floor(number_card / 4000000000000) == 1 && validation == 0)
    {
        printf("VISA\n");
    }
    else if (floor(number_card / 40000000000000) == 1 && validation == 0)
    {
        printf("VISA\n");
    }
    else if (floor(number_card / 400000000000000) == 1 && validation == 0)
    {
        printf("VISA\n");
    }
    else if (floor(number_card / 4000000000000000) == 1 && validation == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
