// Prints right sided pyramid of bricks, using user input for height

#include <cs50.h>
#include <stdio.h>

// Declare print_row function to be able to call it in the main function
void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt user for pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // re-prompting user if out of 1 - 8 range
    while (n < 1 || n > 8);

    // Print pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of spaces and bricks
        print_row(n - i - 1, i + 1);
    }
}

// Function that sets how rows are printed
void print_row(int spaces, int bricks)
{
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    for (int j = 0; j < bricks; j++)
    {
        printf("#");
    }
    printf("\n");
}

// Suppose user entered height of 4
// in the first iteration "i = 0" parameters for print_row(3, 1)
// in the second iteration "i = 1" parameters for print_row(2, 2)
// in the third iteration "i = 2" parameters for print_row(1, 3)
// in the last iteration "i = 3" parameters for print_row(0, 4)
// then "i = 4", i < n condition no longer true.
