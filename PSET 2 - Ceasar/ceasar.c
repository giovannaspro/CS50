/*Implement a program that encrypts messages using Caesar’s cipher*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
/*Call the functions created*/
void caesar(string text, int key);

/*Main function*/
int main(int argc, string argv[])
{
    /*Checks if there is 2 inputs*/
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    /*Checks if the secund input is a digit*/
    for (int i = 0, arraySize = strlen(argv[1]); i < arraySize; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    caesar(plaintext, key);
    return 0;
}

/*Function that will give the answer of the problem*/
void caesar(string plaintext, int key)
{
    int arraySize = strlen(plaintext);
    int ascii_index[arraySize];
    char ciphertext[arraySize];
    /*Do the ciphertext, but taking the integer 
    that corresponds to the ascii index*/
    for (int i = 0; i < arraySize; i++)
    {
        /*For capital letter*/
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ascii_index[i] = ((((int)plaintext[i] - 'A' + key) % 26) + 'A'); 
        }
        /*For lower case*/
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ascii_index[i] = (((int)plaintext[i] - 'a' + key) % 26) + 'a';
        }
        /*For other characters*/
        else
        {
            ascii_index[i] = plaintext[i];
        }
    }
    for (int i = 0; i < arraySize; i++)
    {
        char letter = ascii_index[i];
        ciphertext[i] = letter;
    }
    /*Prints the ciphertext*/
    /*Gives the space required on the specification*/
    printf("ciphertext: %s\n", ciphertext);
}
