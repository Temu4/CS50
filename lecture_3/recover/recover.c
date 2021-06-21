/*
    Recover deleted JPEG files from FAT-formatted card
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover pathToRecoverFile\n");
        return 1;
    }

    char* infile = argv[1];

    // open input file
    FILE* cardFile = fopen(infile, "r");
    if (cardFile == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    typedef uint8_t BYTE;
    BYTE buffer[512];
    int count = 0;
    FILE *imgPointer = NULL;
    char filename[8];

    // read file's content
    // repeat until end of card:
    while (fread(&buffer, 512, 1, cardFile) == 1) {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0)== 0xe0 ) {
            // if not first JPEG, close previous
            if (!(count == 0)) {
                fclose(imgPointer);
            }
            // initialise file
            sprintf(filename, "%03i.jpg", count);
            imgPointer = fopen(filename, "w");
            count++;
        }

        // if JPEG has been found, write to file
        if (!(count == 0)) {
            fwrite(&buffer, 512, 1, imgPointer);
        }
    }

    fclose(cardFile);
    fclose(imgPointer);
    return 0;
}
