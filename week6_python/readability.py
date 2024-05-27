from cs50 import get_string

# Prompt user for text
text = get_string("Text: ")

# Initialize counters
lcount = 0
wcount = 0
scount = 0

# Count the number of letters
for i in text:
    if i.isalnum():
        lcount = lcount + 1
    if i == 96:
        lcount = lcount + 1

# Count the words
for i in text:
    if i.isspace():
        wcount = wcount + 1
wcount = wcount + 1

# Count the sentences
for i in text:
    if i == '!' or i == '?' or i == '.':
        scount = scount + 1

# Calculate average letters per 100 words and average sentences per 100 words
avletters = (lcount / wcount) * 100
avsentences = (scount / wcount) * 100

# Compute the Coleman-Liau Index = 0.0588 * L - 0.296 * S - 15.8
realgrade = (0.0588 * avletters) - (0.296 * avsentences) - 15.8

# Round grade to nearest integer
grade = round(realgrade)

# Print the grade level
if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade is {grade}")