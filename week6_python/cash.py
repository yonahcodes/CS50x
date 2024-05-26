from cs50 import get_float

# Prompt user for change owed (float > 0)
# If negative number, prompt again
while True:
    change = get_float("Change: ")
    if (change > 0):
        break

# Convert change to integer to work with
change = round(change * 100)

# Calculate starting with biggest coin first
quarter = 25
n_quarters = 0

while change >= quarter:
    change = change - quarter
    n_quarters = n_quarters + 1


dime = 10
n_dimes = 0
while change >= dime:
    change = change - dime
    n_dimes = n_dimes + 1

nickel = 5
n_nickels = 0
while change >= nickel:
    change = change - nickel
    n_nickels = n_nickels + 1

penny = 1
n_pennies = 0
while change >= penny:
    change = change - penny
    n_pennies = n_pennies + 1

# Sum the number of coins used
min_coins = (n_quarters + n_dimes + n_nickels + n_pennies)
# Print sum
print(min_coins)
