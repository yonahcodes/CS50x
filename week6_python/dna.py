import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Error: Incorrect number of arguments")
        print("Usage: python dna.py <file.csv> <file.txt>")
        sys.exit(1)

    # Read database file into a variable
    database = sys.argv[1]
    with open(database) as file:
        csv_reader = csv.DictReader(file)
        individuals = list(csv_reader)

        # Isolate strs in a list
        strs = list(individuals[0].keys())[1:]

    # Read DNA sequence file into a variable
    dna_sequence = sys.argv[2]
    with open(dna_sequence) as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for str in strs:
        str_counts[str] = longest_match(sequence, str)

    # Check database for matching profiles
    for person in individuals:
        if all(int(person[str]) == str_counts[str] for str in strs):
            print(person['name'])
            return
    else:
        print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
