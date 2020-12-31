// Implements a dictionary's functionality
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Size of dictionary
int count_word = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //Puts all letters in lowercase
    int arraySize = strlen(word);
    char lowerword[arraySize+1];
    lowerword[arraySize] = '\0';
    for (int i = 0; i < arraySize; i++)
    {
        /*If the letter is lowercase*/
        if (isupper(word[i]))
        {
            lowerword[i] = word[i] + 32;    
        }
        /*If the letter is uppercase*/
        else
        {
            lowerword[i] = word[i];
        }
    }
    
    // Hash word to obtain a hash value
    unsigned int index = hash(lowerword);
    
    // Access linked list at that index in the hash table
    node *cursor1 = table[index];
    
    // Traverse linked list, looking for the word (strcasecmp)
    // Run through memory
    while (cursor1 != NULL)
    {
        //If there's the word
        if (strcasecmp(lowerword, cursor1->word) == 0)
        {
            return true;    
        }
        
        cursor1 = cursor1->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int index = -1;
    int arraySize = strlen(word);
    int ascii_index[arraySize];
    char lower_case[arraySize];
    
    // Make all lowercase
    for (int i = 0; i < arraySize; i++)
    {
        /*If the letter is lowercase*/
        if (isupper(word[i]))
        {
            lower_case[i] = word[i] + 32;    
        }
        /*If the letter is uppercase*/
        else
        {
            lower_case[i] = word[i];
        }
    }

    // See the first letter
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < N; i++)
    {
        // If the first letter is igual to one of the alphabet, this is your index
        if (word[0] == alphabet[i])
        {
            index = i;
        }
    }
    
    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dictionary_file = fopen(dictionary, "r");
    if (dictionary_file == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];
    
    // Read strings from file one at a time
    while (fscanf(dictionary_file, "%s", word) != EOF)
    {
        // Create a new node for each word
        // Add number to list
        node *n = malloc(sizeof(node));
        
        // Check if there is any error
        if (n == NULL)
        {
            return false;
        }
        
        // Function that copies 
        strcpy(n->word, word);
        
        // Hash word to obtain a hash value
        unsigned int index = hash(word);
    
        // Insert node into hash table at that location in the beginning to list
        // When there isn't already a node
        if (table[index] == NULL)
        {
            n->next = NULL;
            table[index] = n;
        }
        
        // When there is already a node
        else
        {
            n->next = table[index];
            table[index] = n;
        }
        
        // Count word for size function
        count_word++;
    }
    
    // Close file
    fclose(dictionary_file);
    
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //Return size dictionary (how many words) calculated on hash table
    return count_word;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //Run through all hash table
    for (int i = 0; i < N; i++)
    {
        // Node pointing to the beginning of the list
        node *cursor2 = table[i];
        
        // Run through all linked list
        while (cursor2 != NULL)
        {
            // Create tmp variable
            node *tmp = cursor2;
            
            // Don't lose track of the linked list
            cursor2 = cursor2->next;
            
            // Free memory
            free(tmp);
        }    
    }
    return true;
}