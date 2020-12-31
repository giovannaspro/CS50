/*Minimum number of coins with which that change can be made*/
void minimum(int cents)
{
    /*Gives the number of coins*/
    int num_coins = 0;
    /*Gives the rest of the division - modulo*/
    int rest = 0;
    
    num_coins = cents / 25;
    rest = cents % 25;
    cents = rest;
    num_coins = num_coins + cents / 10;
    rest = cents % 10;
    cents = rest;
    num_coins = num_coins + cents / 5;
    rest = cents % 5;
    cents = rest;
    num_coins = num_coins + cents / 1;
    rest = cents % 1;

    printf("%d\n", num_coins);
}
