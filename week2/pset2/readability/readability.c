#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main(void)
{
    // get user input
    string s = get_string("Text: ");

    // count string length
    int length = strlen(s);
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // iterate through string
    for (int i = 0; i < length; i++)
    {
        // count for letters
        if (isalpha(s[i]))
        {
            letters++;
        }

        // count for words
        if (isspace(s[i]))
        {
            words++;
        }

        // count for sentences
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }


    // calculate L
    float L = (float) letters / words * 100;
    // calculate S
    float S = (float) sentences / words * 100;
    // calculate index and round to nearest integer
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int roundedIndex = round(index);

    if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundedIndex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}