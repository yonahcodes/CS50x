#include <cs50.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Look for a candidate called name
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate is valid candidate name (strcmp)
        if ((strcmp(candidates[i].name, name)) == 0)
        {
            // Update preferences[i][j] ([i = voter], [j = rank]) update rank to that candidate
            // value
            preferences[voter][rank] = i;
            return true;
        }
    }
    // If no candidate was found, don't update any preferences and return false
    return false;
}

// Update votes for non-eliminated candidates
void tabulate(void)
{
    // Iterate through each voter
    for (int i = 0; i < voter_count; i++)
    {
        // Iterate through the preferences of each voter
        for (int j = 0; j < candidate_count; j++)
        {
            // Starting with candidate in top preference, check if still in the race
            if (!candidates[preferences[i][j]].eliminated)
            {
                // Allocate that vote to candidate's total votes (+1)
                candidates[preferences[i][j]].votes++;
                // Important. Break statement jumps out of the loop to next voter, to only consider
                // top preference If the `break` wasn't there, the inner loop would iterate through
                // all the preferences of one voter Incrementing votes of candidates in all levels
                // and result in inaccurate vote counts.
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // If any candidate has more than half the votes
    for (int i = 0; i < voter_count; i++)
    {
        // If candidates[i] shows up in preference[v][i] > voter_count/2
        if (candidates[i].votes > voter_count / 2)
        {
            // Print out their name and return true
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // If no candidate has majority
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initialize variable with large number that will get updated with number of votes
    int min_votes = INT_MAX;

    // Loop through the candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If candidate are not eliminated
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            // Update votes
            min_votes = candidates[i].votes;
            // find number of votes
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Consider remaining candidates
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Find which candidates have min number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            // Update eliminated status
            candidates[i].eliminated = true;
        }
    }
    return;
}
