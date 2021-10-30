#include <stdio.h>
#include <cs50.h>

// mario/less
// Prompt user for height
// height must be between 1 and 8 inclusive
int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // for loop to create the height of the row
    for (int r = 0; r < height; r++)
    {
        // for loop create the width of the pyramid
        for (int c = 0; c < height; c++)
        {
            // if row plus column is greater than or equal to height -1 space print hashes
            if (r + c >= height - 1)
            {
                printf("#");
            }
            // add spaces from left to right -1 after each row
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}