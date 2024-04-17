#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define 1 byte type
typedef uint8_t BYTE;
// Define block of 512
const int BLOCK = 512;

int main(int argc, char *argv[])
{
    // If more than 2 arguments return error
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card file
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Dynamically allocate memory for 512 byte buffer
    BYTE *buff = malloc(BLOCK);
    if (buff == NULL)
    {
        fclose(card);
        return 1;
    }

    // Initialize file count variable
    int count = 0;
    // Declare file pointer variable 
    FILE *img = NULL;
    // Declare array of 8 elements for filename (xxx.jpg)
    char filename[8];

    // While there is a block of data of (512 bytes) to read from
    while (fread(buff, BLOCK, 1, card) == 1)
    {
        // If first 4 bytes correspond to a JPEG header
        // Bitwise syntax for 4th byte (buff[3]): 
        // `0xf0 &` mask isolates first 4 bits and compares them to 0xe0 first 4 bits
        if (buff[0] == 0xff && buff[1] == 0xd8 && buff[2] == 0xff && (buff[3] & 0xf0) == 0xe0)
        {
            // If a file is open close it (beginning of new file was just found)
            if (img != NULL)
            {
                fclose(img);
            }

            // Generate file name format (xxx.jpg) to be used
            // `%03i` 3 digit integer padded with zero when needed
            // If count is 7, result is 007.jpg 
            sprintf(filename, "%03i.jpg", count);

            // Update count of files created
            count++;

            // Open jpg file to write to
            img = fopen(filename, "wb");
            if (img == NULL)
            {
                fclose(card);
                free(buff);
                return 1;
            }
        }

        // If a file is open write a block to it
        if (img != NULL)
        {
            fwrite(buff, BLOCK, 1, img);
        }
    }

    // If a file is still open, close it
    if (img != NULL)
    {
        fclose(img);
    }
    // Close source file and free the buffer
    fclose(card);
    free(buff);

    return 0;
}
