// Program that prints number of coins needed to make given amount of change
#include <cs50.h>
#include <stdio.h>

// Include prototypes of the functions I will be using in the main function
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt user for change owed input (int > 0)
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    // If Boolean expression in while is true, prompt the user again
    while (cents < 0);

    // Call each function (Biggest first) and substract the value from cents
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // Sum the number of quarters, dimes, nickels, and pennies used
    int change = (quarters + dimes + nickels + pennies);
    // Print sum
    printf("%i\n", change);
}

// Calculate how many quarters we should give
int calculate_quarters(int cents)
{
    int quarter = 25;
    int n_quarters;

    for (n_quarters = 0; cents >= quarter; n_quarters++)
    {
        cents -= quarter;
    }
    return n_quarters;
}

// Calculate how many dimes we should give
int calculate_dimes(int cents)
{
    int dime = 10;
    int n_dimes;

    for (n_dimes = 0; cents >= dime; n_dimes++)
    {
        cents -= dime;
    }
    return n_dimes;
}

// Calculate how many nickels we should give
int calculate_nickels(int cents)
{
    int nickel = 5;
    int n_nickels;

    for (n_nickels = 0; cents >= nickel; n_nickels++)
    {
        cents -= nickel;
    }
    return n_nickels;
}

// Calculate how many pennies we should give
int calculate_pennies(int cents)
{
    int penny = 1;
    int n_pennies;

    for (n_pennies = 0; cents >= penny; n_pennies++)
    {
        cents -= penny;
    }
    return n_pennies;
}
