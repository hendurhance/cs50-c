#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // if argc is not 2, print error message and exit
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // open card.raw
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    // read file into buffer and look for JPEGs
    BYTE buffer[512];
    int jpg_count = 0;
    FILE *img_pointer = NULL;
    char img_name[8];

    while (fread(buffer, 512, 1, file) == 1)
    {
        // if buffer is a jpeg, write to file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            // if not first jpeg, close previous file
            if (jpg_count > 0)
            {
                fclose(img_pointer);
            }

            // initialize new file name
            sprintf(img_name, "%03i.jpg", jpg_count);
            img_pointer = fopen(img_name, "w");
            jpg_count++;
        }

        // write buffer to file
        if (img_pointer != NULL)
        {
            fwrite(buffer, 512, 1, img_pointer);
        }

    }

    // close file
    fclose(file);
    fclose(img_pointer);

    return 0;

}
