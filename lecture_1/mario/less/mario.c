#include <cs50.h>
#include <stdio.h>

void buildPyramid(int);

int main(void) {
    int height;

    do {
       height = get_int("Height: ");
    } while (height <= 0 || height > 8);

    buildPyramid(height);
}

void buildPyramid(int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 1; j < height - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}