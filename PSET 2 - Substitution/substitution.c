/*Implement a program that implements a substitution cipher*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

string key;

/*Call the functions created*/
void substitution(string plaintext, string upperKey, int arraySize);
int verifyKey(int arraySize);

/*Main function*/
int main(int argc, string argv[])
{
    /*Checks if there is 2 inputs*/
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int arraySize = strlen(argv[1]);
    key = argv[1];
    
    //verifyKey(arraySize);
    for (int i = 0; i < arraySize; i++)
    {
        /*Checks if it's alpha*/
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
        /*Checks the size*/
        else if (arraySize != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    
    /*Makes the key all in uppercase*/
    char upperKey[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        /*If the letter is lowercase*/
        if (islower(argv[1][i]))
        {
            upperKey[i] = argv[1][i] - 32;    
        }
        /*If the letter is uppercase*/
        else
        {
            upperKey[i] = argv[1][i];
        }
    }
    /*Taking the plaintext*/
    string plaintext = get_string("plaintext: ");
    int textSize = strlen(plaintext);
    /*Calling the function that will solve the problem*/
    substitution(plaintext, upperKey, textSize);
    return 0;
}

/*Function that will give the answer of the problem*/
void substitution(string plaintext, string upperKey, int arraySize)
{
    char ciphertext[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        /*Checks the upper case*/
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = upperKey[plaintext[i] - 65];
        }
        /*Checks the lower case*/
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = upperKey[plaintext[i] - 97];
            ciphertext[i] = tolower(ciphertext[i]);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    /*Prints the ciphertext*/
    /*Gives the space required on the specification*/
    printf("ciphertext: %s\n", ciphertext);
}
