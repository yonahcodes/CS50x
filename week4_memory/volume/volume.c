// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open original input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Open output file to be generated
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Converts factor input string into float to be used to compute
    float factor = atof(argv[3]);

    // Dynamically allocate space in the heap for a header in pointer variable buffer1
    uint8_t *buffer1 = malloc(HEADER_SIZE * sizeof(uint8_t));
    if (buffer1 == NULL)
    {
        return 1;
    }

    // Copy header from input file to output file
    fread(buffer1, HEADER_SIZE, 1, input);
    fwrite(buffer1, HEADER_SIZE, 1, output);

    // Free buffer1
    free(buffer1);

    // Dynamically allocate space in the heap for a sample in pointer variable buffer2
    int16_t *buffer2 = malloc(sizeof(int16_t));
    if (buffer2 == NULL)
    {
        return 1;
    }

    // Read the data into buffe2 (fread() will continue to next unread bit)
    while (fread(buffer2, sizeof(int16_t), 1, input) != 0)
    {
        // Dereference buffer2 pointer and multiply the value it points to by the factor
        *buffer2 *= factor;

        // Write new data to output file
        fwrite(buffer2, sizeof(int16_t), 1, output);
    }

    // Free buffer2
    free(buffer2);

    // Close files
    fclose(input);
    fclose(output);
}
