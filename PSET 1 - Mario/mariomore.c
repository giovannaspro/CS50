//Write a program in C to display the pattern like right angle triangle using an asterisk.
#include <stdio.h>
#include <cs50.h>

void pyramids(int n);

int main(void)
{
    int n = get_int("Height: ");
    while(n <= 0)
    {
        n = get_int("Height: ");
    }
    pyramids(n);    
}

void pyramids(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int k = n-i-1; k >= 0; k--)
        {
            printf(" ");
        }
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
