#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Iterate over each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate name matches given name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // Increment candidate's votes
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Initialize highest votes to first candidate
    // This line had a bug I spend a long time trying to correct
    // I was initializing the votes to 0, not to candidates[0].votes 
    int highest_votes = candidates[0].votes;

    // Iterate through every other candidate
    for (int i = 1; i < candidate_count; i++)
    {
        // If one of the candidates has more votes than the previous
        if (candidates[i].votes > highest_votes)
        {
            // Update highest vote to that candidate
            highest_votes = candidates[i].votes;
        }
    }

    // Print the candidate (or candidates) with maximum votes
    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == highest_votes)
        {
            printf("%s\n", candidates[j].name);
        }
    }
}
