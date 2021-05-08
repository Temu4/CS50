#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int alphabetLength = 26;
    int indexLastUppercaseLetter = 90;
    int indexLastLowercaseLetter = 122;

    //check if at least one argument is entered
    if (argc != 2) {
        printf("Usage: ./caesar key\n");
        return 1;
    } else {
        string keyString = argv[1];
        //check if all characters in the key is a digit
        for (int i = 0, n = strlen(keyString); i < n; i++){
            if(!isdigit(keyString[i])){
                printf("Usage: ./caesar key\n");
                return 2;
            }
        }
        //convert string to int
        int key = atoi(keyString);
        //check if an argment is a number > 0
        if (key > 0) {
            //cut off how much times key overrides an alphabet
            int cleanKey = key % alphabetLength;
            
            string message = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0, n = strlen(message); i < n; i++) {
                char p = message[i];
                if(isalpha(p)){
                    int c = (p + cleanKey);
                    //if character is in uppercase
                    if(isupper(p)){
                        if(c > indexLastUppercaseLetter){
                            c -= alphabetLength;
                        }
                    }
                    //if character is in lovercase
                    if(islower(p)){
                        if(c > indexLastLowercaseLetter){
                            c -= alphabetLength;

                        }
                    }
                    printf("%c", c);
                } else {
                    printf("%c", message[i]);
                }
            }
            printf("\n");
        } else {
            printf("Usage: ./caesar key\n");
            return 3;
        }
    } 
}
