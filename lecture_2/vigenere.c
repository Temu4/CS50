#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
  int alphabetLength = 26;
  int indexLastUppercaseLetter = 90;
  int indexLastLowercaseLetter = 122;

    //check if at least one argument is entered
    if (argc != 2) {
      printf("Usage: ./vigenere key\n");
      return 1;
    } else {
        string keyString = argv[1];
        int keyLength = strlen(keyString);

      //check if all characters in the key are letters
      bool isDigit = false;
      for (int i = 0; i < keyLength; i++){
          if (isdigit(keyString[i])) {
              isDigit = true;
          }
      }
      if (isDigit) {
          printf("Usage: ./vigenere key\n");
          return 1;
      } else {
          string message = get_string("plaintext: ");
          int plaintextLength = strlen(message);
          printf("ciphertext: ");

          for (int i = 0, j = 0; i < plaintextLength; i++, j++) {
              char p = message[i];

              //reset counter for key if it out of the range
              if (j >= keyLength) {
                j = 0;
              }

              int shiftValue = shift(keyString[j]);

              // if character isn't a number
              if(isalpha(p)){
                  int c = (p + shift(keyString[j]));
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
                  //reduce key counter to handle increment for not letters
                  j--;
                  printf("%c", message[i]);
              }
          }
          printf("\n");
          return 0;
      }
    } 
}

int shift(char c){
    if (c >= 65 && c < 97) {
        return c - 65;
    } else {
        return c - 97;
    }
}
