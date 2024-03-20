#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //  Make sure command line argument is good format
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a string to an int to be able to calculate
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plain = get_string("plaintext:  ");

    // Print ciphertext
    printf("ciphertext: ");
    // Iterate through plaintext and put every char through formula
    for (int i = 0, len = strlen(plain); i < len; i++)
    {
        // Call rotate function in printf
        printf("%c", rotate(plain[i], key));
    }
    printf("\n");

    return 0;
}

// Check if key is made of digits
bool only_digits(string key)
{
    // Iterate through every char of string
    for (int i = 0, len = strlen(key); i < len; i++)
    {
        // If any character is not a digit
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}

// Put chars through Ci = (Pi + k) % 26 formula
char rotate(char c, int k)
{
    // Two different conditions to preserve Case
    if (isupper(c))
    {
        // (c - 'A') converts char from ASCII value to alphabetical index
        // (+ k) to shift "key amount" of indexes
        // (% 26) ensures wrap around after Z
        // If index is 27, % 26 will give 1 (27%26=1) bringing it back to the start
        // (c += 'A') converts bach alphabetical index to new ASCII value
        c = ((c - 'A' + k) % 26) + 'A';
    }
    else if (islower(c))
    {
        c = ((c - 'a' + k) % 26) + 'a';
    }
    // Return unchanged is not a letter
    return c;
}