#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*Call the functions created*/
int count_letter(string text);
int count_word(string text);
int count_sentences(string text);
void grade(int n_letter, int n_word, int n_sentence);
/*Main function*/
int main(void)
{
    string text = get_string("Text: ");
    /*This function takes de value of each aspect*/
    grade(count_letter(text), count_word(text), count_sentences(text));
}
/*Count how many letters*/
int count_letter(string text)
{
    int n_total = strlen(text);
    int n_letter = 0;
    for (int i = 0; i < n_total; i++)
    {
        if (isalpha(text[i]))
        {
            n_letter++;
        }
    }
    return n_letter;
}
/*Count how many words*/
int count_word(string text)
{
    int n_word = 1;
    int n_total = strlen(text);
    for (int i = 0; i < n_total; i++)
    {
        if (isspace(text[i]))
        {
            n_word++;
        }
    }
    return n_word;
}
/*Count how many sentences*/
int count_sentences(string text)
{
    int n_sentence = 0;
    int n_total = strlen(text);
    for (int i = 0; i < n_total; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            n_sentence++;
        }
    }
    return n_sentence;
}

/*Gives the result the problem wants*/
/*Do the index*/
/*Gives de answer*/
void grade(int n_letter, int n_word, int n_sentence)
{
    float L = (n_letter / (float)(n_word)) * 100;
    float S = (n_sentence / (float)(n_word)) * 100;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int grade = round(index);
        printf("Grade %i\n", grade);
    }
}
