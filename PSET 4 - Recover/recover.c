#include <stdio.h>
#include <stdlib.h>

//Global variables
#define JPEG_SIZE 512
#define FILE_SIZE 8

int main(int argc, char *argv[])
{
    //Check usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    //Open memory card
    FILE *memory_card = fopen(argv[1], "r");
    if (!memory_card)
    {
        printf("There is no file!\n");
        return 1;
    }
    
    //Read the memory card
    unsigned char buffer[JPEG_SIZE];
    
    //Count how many jpeg files are inside
    int count_jpeg = 0;
    
    //Creating a new file
    FILE *images_recovered;
    
    //Condition to see if its first JPEG
    // 0 represents false
    int first_JPEG = 0;
    
    //Repeat until end of card
    while ((fread(buffer, JPEG_SIZE, 1, memory_card)) == 1)
    {
        //Read 512 bytes into a buffer
        //If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //If first JPEG
            if (first_JPEG == 0)
            {
                //1 represents true
                first_JPEG = 1;
            }
            
            //If it's not the first JPEG, you have to close the file you just been writing to
            else
            {
                fclose(images_recovered);
            }
            
            //Had to do filename because of sprintf
            char filename[FILE_SIZE];
            //Recover the JPEG
            sprintf(filename, "%03i.jpg", count_jpeg);
            //Increments the number of the jpg
            count_jpeg++;
            //Creates a new file and write on it
            images_recovered = fopen(filename, "w");
            //Write on the file
            fwrite(buffer, 512, 1, images_recovered);
        }
        //If it's not the start of a new JPEG
        else
        {
            //If already found JPEG
            if (first_JPEG == 1)
            {
                //Keep writing the jpg
                fwrite(buffer, 512, 1, images_recovered);
            }
        }
    }
    
    //Close any remaining files
    fclose(memory_card);
    fclose(images_recovered);
}