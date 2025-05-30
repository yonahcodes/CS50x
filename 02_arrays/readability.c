// Calculate approximate grade level of text using Coleman-Lau index
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string letters);
int count_words(string words);
int count_sentences(string sentences);

int main(void)
{
    // Prompt user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int lcount = count_letters(text);
    int wcount = count_words(text);
    int scount = count_sentences(text);

    // Calculate average letters per 100 words and average sentences per 100 words
    float avletters = ((float) lcount / (float) wcount) * 100;
    float avsentences = ((float) scount / (float) wcount) * 100;

    // Compute the Coleman-Liau Index = 0.0588 * L - 0.296 * S - 15.8
    float real_grade = (0.0588 * avletters) - (0.296 * avsentences) - 15.8;

    // Round grade to nearest integer
    int grade = round(real_grade);

    // Print the grade level
    if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %i", grade);
    }
    printf("\n");
}

int count_letters(string letters)
{
    // Initialize count
    int lcount = 0;

    // Loop through each of the text characters
    for (int i = 0, len = strlen(letters); i < len; i++)
    {
        // If character is alphanumerical, add 1 to letter count
        if (isalpha(letters[i]))
        {
            lcount++;
        }
        // If character is equal to ASCII value for apostrophe, add 1 to letter count
        if (letters[i] == 96)
        {
            lcount++;
        }
    }
    return lcount;
}

int count_words(string words)
{
    // Initialize count
    int wcount = 0;

    // Loop through each of the text characters
    for (int i = 0, len = strlen(words); i < len; i++)
    {
        // If character is a space add 1 to word count
        if (isspace(words[i]))
        {
            wcount++;
        }
    }
    // Return number of spaces + 1, equivalent to number of words
    return wcount + 1;
}

int count_sentences(string sentences)
{
    // Initialize count
    int scount = 0;

    // Loop through each of the text characters
    for (int i = 0, len = strlen(sentences); i < len; i++)
    {
        // If character is equal to ASCII value of "!" add 1 to sentence count
        if (sentences[i] == 33)
        {
            scount++;
        }
        // If character is equal to ASCII value of "." add 1 to sentence count
        else if (sentences[i] == 46)
        {
            scount++;
        }
        // If character is equal to ASCII value of "?" add 1 to sentence count
        else if (sentences[i] == 63)
        {
            scount++;
        }
    }
    // return number of punctuation characters (eqv to sentences)
    return scount;
}