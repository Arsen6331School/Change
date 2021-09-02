#include <stdio.h>

float get_valid_change();
float get_change();

// Available denominations
static int DENOMINATION_VALS[5] = {50, 25, 10, 5, 1};

int main()
{
    // Get user input from stdin
    float change = get_valid_change();
    // Convert dollars to cents
    int cents = (int)(change * 100);
    
    // Initialize coin amount at 0
    int coin_amount = 0;
    for (int i = 0; i < 5; i++) 
    {
        // Get current denomination
        int denomination = *(DENOMINATION_VALS + i);
        // Get amount of denomination required
        int amt_den = cents / denomination;
        // Add amount requrired to coin amount
        coin_amount += amt_den;
        // Subtract used cents from cents
        cents -= denomination * amt_den;
    }
    // Print amount of coins
    printf("%i\n", coin_amount);

}


// get_valid_change asks for a float until a valid one is given
float get_valid_change()
{
    float change;
    do 
    {
        change = get_change();
    }
    while (change < 0);
    return change;
}

// get_change asks the user for change
float get_change()
{
    // Print prompt
    printf("Change owed: ");
    char input[100];
    // Get input string
    fgets(input, 100, stdin);
    float change;
    // Scan input string for integer
    sscanf(input, "%f", &change);
    return change;
}


