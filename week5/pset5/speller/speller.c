// Implements a dictionary's functionality

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 50000;

// Hash table
node *table[N];

// Number of words in dictionary
int count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int value = hash(word);

    node *cursor = table[value];

    // iterate through linked list
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    // initialize hash value
    unsigned int hash_val = 0;

    // for each character in word
    for (int i = 0; i < strlen(word); i++)
    {
        hash_val += tolower(word[i]);
        hash_val = (hash_val * tolower(word[i])) % N;
    }

    return hash_val;
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO

    // open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }

    // iterate through dictionary
    char wordlist[LENGTH + 1];

    // while there are words in the dictionary
    while (fscanf(file, "%s", wordlist) != EOF)
    {
        // increment count
        count++;

        // create new node for each word
        node *new_node = malloc(sizeof(node));

        //check for null
        if (new_node == NULL)
        {
            return 1;
        }

        // copy word into new node
        strcpy(new_node->word, wordlist);
        new_node->next = NULL;

        // hash word
        int value = hash(wordlist);

        // if table[value] is NULL
        if (table[value] == NULL)
        {
            table[value] = new_node;
        }

        else
        {
            // new_node is now the head
            new_node->next = table[value];
            table[value] = new_node;
        }
    }
    // close dictionary
    fclose(file);

    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // track number of words
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // iterate through table
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;

            free(tmp);
        }
    }
    return true;
}