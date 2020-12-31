#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Columns = height
    for (int i = 0; i < height; i++)
    {
        //Rows = width
        for (int j = 0; j < width; j++)
        {
            //Takes each pixel's color
            int grayRed = image[i][j].rgbtRed;
            int grayGreen = image[i][j].rgbtGreen;
            int grayBlue = image[i][j].rgbtBlue;
            //Takes the average of it
            int average = round(((float)grayRed + (float)grayBlue + (float)grayGreen) / 3);
            //Changes the pixel's color
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Columns = height
    for (int i = 0; i < height; i++)
    {
        //Rows = width
        for (int j = 0; j < width; j++)
        {
            //Takes each pixel's color
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            //Does the sepia color values
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            image[i][j].rgbtRed = fmin(255, sepiaRed);    
            
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE reflection[height][width];
    //Does the reflection
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, limit = (width / 2); j < limit; j++)
        {
            //swap(&arr[i],&arr[width-i]);
            //int tmp = *a;
            //*a = *b;
            //*b = tmp;
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Creates a new array with the original values
    RGBTRIPLE original_values[height][width];
    //Columns = height
    for (int i = 0; i < height; i++)
    {
        //Rows = width
        for (int j = 0; j < width; j++)
        {
            original_values[i][j] = image[i][j];
        }
    }
    //Does the blur image
    //Columns = height
    for (int i = 0; i < height; i++)
    {
        //Rows = width
        for (int j = 0; j < width; j++)
        {
            //Top-left corner
            if (i == 0 && j == 0)
            {
                int averageRed = round(((float)original_values[i][j + 1].rgbtRed + (float)original_values[i + 1][j].rgbtRed + (float)original_values[i + 1][j + 1].rgbtRed + (float)original_values[i][j].rgbtRed) / 4);
                int averageBlue = round(((float)original_values[i][j + 1].rgbtBlue + (float)original_values[i + 1][j].rgbtBlue + (float)original_values[i + 1][j + 1].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 4);
                int averageGreen = round(((float)original_values[i][j + 1].rgbtGreen + (float)original_values[i + 1][j].rgbtGreen + (float)original_values[i + 1][j + 1].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 4);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Bottom-left corner
            else if (i == 0 && j == (width - 1))
            {
                int averageRed = round(((float)original_values[i][j - 1].rgbtRed + (float)original_values[i + 1][j].rgbtRed + (float)original_values[i + 1][j - 1].rgbtRed + (float)original_values[i][j].rgbtRed) / 4);
                int averageBlue = round(((float)original_values[i][j - 1].rgbtBlue + (float)original_values[i + 1][j].rgbtBlue + (float)original_values[i + 1][j - 1].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 4);
                int averageGreen = round(((float)original_values[i][j - 1].rgbtGreen + (float)original_values[i + 1][j].rgbtGreen + (float)original_values[i + 1][j - 1].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 4);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Bottom-right corner
            else if (i == (height - 1) && j == (width - 1))
            {
                int averageRed = round(((float)original_values[i][j - 1].rgbtRed + (float)original_values[i - 1][j].rgbtRed + (float)original_values[i - 1][j - 1].rgbtRed + (float)original_values[i][j].rgbtRed) / 4);
                int averageBlue = round(((float)original_values[i][j - 1].rgbtBlue + (float)original_values[i - 1][j].rgbtBlue + (float)original_values[i - 1][j - 1].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 4);
                int averageGreen = round(((float)original_values[i][j - 1].rgbtGreen + (float)original_values[i - 1][j].rgbtGreen + (float)original_values[i - 1][j - 1].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 4);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Top-right corner
            else if (i == (height - 1) && j == 0)
            {
                int averageRed = round(((float)original_values[i][j + 1].rgbtRed + (float)original_values[i - 1][j].rgbtRed + (float)original_values[i - 1][j + 1].rgbtRed + (float)original_values[i][j].rgbtRed) / 4);
                int averageBlue = round(((float)original_values[i][j + 1].rgbtBlue + (float)original_values[i - 1][j].rgbtBlue + (float)original_values[i - 1][j + 1].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 4);
                int averageGreen = round(((float)original_values[i][j + 1].rgbtGreen + (float)original_values[i - 1][j].rgbtGreen + (float)original_values[i - 1][j + 1].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 4);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Fisrt row
            else if ((i > 0 || i < (height - 1)) && j == 0)
            {
                int averageRed = round(((float)original_values[i][j + 1].rgbtRed + (float)original_values[i - 1][j].rgbtRed + (float)original_values[i - 1][j + 1].rgbtRed + (float)original_values[i + 1][j + 1].rgbtRed + (float)original_values[i + 1][j].rgbtRed + (float)original_values[i][j].rgbtRed) / 6);
                int averageBlue = round(((float)original_values[i][j + 1].rgbtBlue + (float)original_values[i - 1][j].rgbtBlue + (float)original_values[i - 1][j + 1].rgbtBlue + (float)original_values[i + 1][j + 1].rgbtBlue + (float)original_values[i + 1][j].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 6);
                int averageGreen = round(((float)original_values[i][j + 1].rgbtGreen + (float)original_values[i - 1][j].rgbtGreen + (float)original_values[i - 1][j + 1].rgbtGreen + (float)original_values[i + 1][j + 1].rgbtGreen + (float)original_values[i + 1][j].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 6);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Last row
            else if ((i > 0 || i < (height - 1)) && j == (width - 1))
            {
                int averageRed = round(((float)original_values[i][j - 1].rgbtRed + (float)original_values[i - 1][j].rgbtRed + (float)original_values[i - 1][j - 1].rgbtRed + (float)original_values[i + 1][j - 1].rgbtRed + (float)original_values[i + 1][j].rgbtRed + (float)original_values[i][j].rgbtRed) / 6);
                int averageBlue = round(((float)original_values[i][j - 1].rgbtBlue + (float)original_values[i - 1][j].rgbtBlue + (float)original_values[i - 1][j - 1].rgbtBlue + (float)original_values[i + 1][j - 1].rgbtBlue + (float)original_values[i + 1][j].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 6);
                int averageGreen = round(((float)original_values[i][j - 1].rgbtGreen + (float)original_values[i - 1][j].rgbtGreen + (float)original_values[i - 1][j - 1].rgbtGreen + (float)original_values[i + 1][j - 1].rgbtGreen + (float)original_values[i + 1][j].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 6);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //First colum
            else if (i == 0 && (j > 0 || j < (width - 1)))
            {
                int averageRed = round(((float)original_values[i][j - 1].rgbtRed + (float)original_values[i][j + 1].rgbtRed + (float)original_values[i + 1][j - 1].rgbtRed + (float)original_values[i + 1][j + 1].rgbtRed + (float)original_values[i + 1][j].rgbtRed + (float)original_values[i][j].rgbtRed) / 6);
                int averageBlue = round(((float)original_values[i][j - 1].rgbtBlue + (float)original_values[i][j + 1].rgbtBlue + (float)original_values[i + 1][j - 1].rgbtBlue + (float)original_values[i + 1][j + 1].rgbtBlue + (float)original_values[i + 1][j].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 6);
                int averageGreen = round(((float)original_values[i][j - 1].rgbtGreen + (float)original_values[i][j + 1].rgbtGreen + (float)original_values[i + 1][j - 1].rgbtGreen + (float)original_values[i + 1][j + 1].rgbtGreen + (float)original_values[i + 1][j].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 6);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Last colum
            else if (i == (height - 1) && (j > 0 || j < (width - 1)))
            {
                int averageRed = round(((float)original_values[i][j - 1].rgbtRed + (float)original_values[i][j + 1].rgbtRed + (float)original_values[i - 1][j - 1].rgbtRed + (float)original_values[i - 1][j + 1].rgbtRed + (float)original_values[i - 1][j].rgbtRed + (float)original_values[i][j].rgbtRed) / 6);
                int averageBlue = round(((float)original_values[i][j - 1].rgbtBlue + (float)original_values[i][j + 1].rgbtBlue + (float)original_values[i - 1][j - 1].rgbtBlue + (float)original_values[i - 1][j + 1].rgbtBlue + (float)original_values[i - 1][j].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 6);
                int averageGreen = round(((float)original_values[i][j - 1].rgbtGreen + (float)original_values[i][j + 1].rgbtGreen + (float)original_values[i - 1][j - 1].rgbtGreen + (float)original_values[i - 1][j + 1].rgbtGreen + (float)original_values[i - 1][j].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 6);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
            //Normal case
            //if ((i > 0 && i < (height - 1)) && (j > 0 && j < (width - 1)))
            else
            {
                int averageRed = round(((float)original_values[i][j - 1].rgbtRed + (float)original_values[i][j + 1].rgbtRed + (float)original_values[i - 1][j - 1].rgbtRed + (float)original_values[i - 1][j + 1].rgbtRed + (float)original_values[i - 1][j].rgbtRed + (float)original_values[i + 1][j].rgbtRed + (float)original_values[i + 1][j - 1].rgbtRed + (float)original_values[i + 1][j + 1].rgbtRed + (float)original_values[i][j].rgbtRed) / 9);
                int averageBlue = round(((float)original_values[i][j - 1].rgbtBlue + (float)original_values[i][j + 1].rgbtBlue + (float)original_values[i - 1][j - 1].rgbtBlue + (float)original_values[i - 1][j + 1].rgbtBlue + (float)original_values[i - 1][j].rgbtBlue + (float)original_values[i + 1][j].rgbtBlue + (float)original_values[i + 1][j - 1].rgbtBlue + (float)original_values[i + 1][j + 1].rgbtBlue + (float)original_values[i][j].rgbtBlue) / 9);
                int averageGreen = round(((float)original_values[i][j - 1].rgbtGreen + (float)original_values[i][j + 1].rgbtGreen + (float)original_values[i - 1][j - 1].rgbtGreen + (float)original_values[i - 1][j + 1].rgbtGreen + (float)original_values[i - 1][j].rgbtGreen + (float)original_values[i + 1][j].rgbtGreen + (float)original_values[i + 1][j - 1].rgbtGreen + (float)original_values[i + 1][j + 1].rgbtGreen + (float)original_values[i][j].rgbtGreen) / 9);
                image[i][j].rgbtRed = averageRed; 
                image[i][j].rgbtBlue = averageBlue;
                image[i][j].rgbtGreen = averageGreen;
            }
        }
    }
    return;
}