// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 1757;

// Hash table
node *table[N];

// Initialize counter for words added to table
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word
    int b = hash(word);

    // Create traversal pointer
    node *trv = table[b];

    // Access value at hash location
    while (trv != NULL)
    {
        if (strcasecmp(word, trv->word) == 0)
        {
            return true;
        }
        trv = trv->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Initialize counter variable
    int sum = 0;

    // Initialize prime base number
    // Each char will be a number in some base b
    // To create different hash codes for similar words
    int b = 31;

    // Loop through each character until "\0"
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Convert chars to lowercase (case INsensitive)
        int lower_char = tolower(word[i]);

        // Multiply sum by b and add ASCII value
        sum = sum * b + lower_char;
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open file passed in as *dictionary
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // Read words into character array buffer of length 45
    char buffer_word[LENGTH + 1];

    while (fscanf(source, "%s", buffer_word) != EOF)
    {
        // Create new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // Copy word from buffer word to node
        strcpy(n->word, buffer_word);
        n->next = NULL;

        // Hash word to get index
        int i = hash(n->word);

        // Insert word at that location in hash table
        if (table[i] == NULL)
        {
            table[i] = n;
            word_count++;
        }
        else
        {
            n->next = table[i];
            table[i] = n;
            word_count++;
        }
    }

    // Close dictionary
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Check if word count set up in load() is empty
    if (word_count == 0)
    {
        return 0;
    }
    else
    {
        return word_count;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through the hash table and free all memory
    for (int i = 0; i < N; i++)
    {
        // Create a traversal and point to bucket i
        node *trv = table[i];

        // If bucket is not empty
        while (trv != NULL)
        {
            // Create temporary pointer and set to next node
            // Free current node
            // Update traversal to next node
            node *temp = trv->next;
            free(trv);
            trv = temp;
        }
        table[i] = NULL;
    }
    return true;
}
