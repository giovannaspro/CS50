//Write a program in C to display the pattern like right angle triangle using an asterisk.
#include <stdio.h>
#include <cs50.h>

void pyramids(int n);

/*Main function*/
int main(void)
{
    int n = get_int("Height: ");
    while (n <= 0 || n >= 9)
    {
        n = get_int("Height: ");
    }
    pyramids(n);
}

/*Function that creates the blocks*/
void pyramids(int n)
{
    /*Create the colums*/
    for (int colum = 0; colum < n; colum++)
    {
        /*Create the rows*/
        for (int k = n - colum - 2; k >= 0; k--)
        {
            printf(" ");
        }
        for (int row = 0; row <= colum; row++)
        {
            if (row == colum)
            {
                printf("#  ");
                /*Create that different part of mario less*/
                for (int j = 0; j <= colum; j++)
                {
                    if (j == 0)
                    {
                        printf("#");
                    }
                    else
                    {    
                        printf("#");
                    }
                }
            }
            else
            {
                printf("#");
            }
        }
        
        printf("\n");
    }
}
