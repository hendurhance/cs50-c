#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// substitution
void substitution();
// get alphabet array value
void alphabetArray(char pos, string key);


int main(int argc, string argv[])
{
    // check no. of terminal command
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            // iterate string and validate
            for (int i = 0; i < strlen(argv[1]) ; i++)
            {

                // check if key is alphabet
                if (!isalpha(argv[1][i]))
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                // check for character duplicate
                for (int j = i + 1 ; j < strlen(argv[1]) ; j++)
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must contain 26 diffrent characters.\n");
                        return 1;
                    }
                }
            }

            // call substitution fn
            substitution(argv[1]);

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}


void substitution(string key)
{
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char p = plaintext[i];
            if (islower(plaintext[i]))
            {
                // parse as lower
                alphabetArray(tolower(p), key);
            }
            else
            {
                // parse as UPPER
                alphabetArray(toupper(p), key);
            }


        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");

}

// Alphabet array fns
void alphabetArray(char pos, string key)
{
    // alpha array
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // iterate and check for cases
    for (int i = 0; i < strlen(alphabet); i++)
    {
        // if its lowercase
        if (islower(pos))
        {
            if (pos == tolower(alphabet[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else
        {
            if (pos == toupper(alphabet[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}