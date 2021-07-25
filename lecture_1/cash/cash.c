#include <math.h>
#include <cs50.h>
#include <stdio.h>

int main(void){
    float change;
    int coins = 0;

    do{
       change = get_float("Change owed: ");
    } while (change && change < 0);

    if(change > 0){
        int cents = round(change * 100);
        int coins25 = cents / 25;
        coins += coins25;

        int change25 = cents % 25;

        if(change25 > 0 ){
            int coins10 = change25 / 10;
            coins += coins10;
            int change10 = change25 % 10;

            if(change10 > 0 ){
                int coins5 = change10 / 5;
                coins += coins5;
                int change5 = change10 % 5;
                coins += change5;
            }
        }
    }

    printf("%i\n", coins);
}
