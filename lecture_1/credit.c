#include <cs50.h>
#include <stdio.h>
#include <math.h>

bool check_sum(long number);
void print_card_logo(long number);

int main(void) {
    long number;

    do {
        number = get_long("Number: ");
    } while(!number || number < 0);

    int number_length = (int)(number ? log10(number) + 1 : 1);

    if ((number_length == 13 || number_length == 15 || number_length == 16) && check_sum(number)) {
        print_card_logo(number);
    } else {
        printf("INVALID\n");
    }
}

bool check_sum(long number) {
    int sum = 0;

    for (int i = 0; number !=0; i++, number /= 10) {
        if (i % 2 == 0){
            sum += number % 10;
        } else {
            int digit = 2 * (number % 10);
            sum += digit /10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}

void print_card_logo(long number){
    if  ((number >= 34e13 && number < 35e13) || (number >= 37e13 && number < 38e13)){
         printf("AMEX\n");
    }
    if  (number >= 51e14 && number < 56e14){
         printf("MASTERCARD\n");
    }
        if  ((number >= 4e12 && number < 5e12) || (number >= 4e15 && number < 5e15)){
         printf("VISA\n");
    }
}
