#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float change;
    int i = 0;
    int j;

    do
    {   
        change = get_float("Change owed:");
    }
    while (change < 0);

    int cents = round(change * 100);
    
    j = cents / 25;           //25cents
    cents = cents - j * 25;
    i += j;

    j = cents / 10;            //10cents
    cents = cents - j * 10;
    i += j;
    
    j = cents / 5;             //5cents
    cents = cents - j * 5;
    i += j;
    
    j = cents / 1;             //1cents
    i += j;

    printf("%i\n", i);
}
