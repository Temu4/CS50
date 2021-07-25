from cs50 import get_float

coins = 0

while True:
    change = get_float("Change owed: ")

    if change and change > 0:
        break

cents = round(change * 100)
coins25 = cents // 25
coins += coins25

# remainder of the division by 25
change25 = cents % 25

if change25 > 0:
    coins10 = change25 // 10
    coins += coins10

    # remainder of the division by 10
    change10 = change25 % 10

    if change10 > 0:
        coins5 = change10 // 5
        coins += coins5
        change5 = change10 % 5

        coins += change5

print(coins)