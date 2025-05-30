#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Find score for given string 
int compute_score(string word)
{
    // Initialize score
    int score = 0;

    // Iterate through each character of word
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        // If character is uppercase
        if (isupper(word[i]))
        {
            // First iteration word[0]
            // word[0] holds ASCII value of first char of word
            // Assume first character is "C", word[0] = 67
            // [word[0] - 'A'] subtracts ASCII value of 'A' (65) to word[0]
            // In our example it would be 67 - 65
            // Resulting value of "2" is then assigned as index to POINT[2]
            // POINT[2] accesses value or third place in array POINTS[], which is 3
            // 3 is then assigned as a value to the score
            // In the next iterations score will update adding new retrieved score values
            // score = score + POINTS[word[i] - 'A'];
            // Until it runs through every char of word and returns total score 
            score += POINTS[word[i] - 'A'];
        }
        // If character is lowercase
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}