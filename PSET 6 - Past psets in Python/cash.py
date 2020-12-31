from cs50 import get_float

float_change = get_float("Change owed: ")
int_change = round(float_change * 100)

while (int_change <= 0):
    float_change = get_float("Change owed: ")
    int_change = round(float_change * 100)

cents = int_change

#Gives the number of coins
num_coins = 0
#Gives the rest of the division - modulo
rest = 0
    
num_coins = cents // 25
rest = cents % 25
cents = rest

num_coins = num_coins + cents // 10
rest = cents % 10
cents = rest

num_coins = num_coins + cents // 5
rest = cents % 5
cents = rest

num_coins = num_coins + cents // 1
rest = cents % 1

print(num_coins)