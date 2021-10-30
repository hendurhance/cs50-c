#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    float change_owed;
    
    do
    {
        change_owed = get_float("Change owed: ");
    }
    while
    (change_owed < 0);

    int num_coins = 0;

    // convert to float to avoid integer division
    int change_owed_int = round(change_owed * 100);

    // loop till no more change is owed
    while
    (change_owed_int > 0)
    {
        // if change_owed_int is subtracted by 25, then 25 cents is removed from change_owed_int and num_coins is incremented by 1
        if
        (change_owed_int - 25 >= 0)
        {
            change_owed_int -= 25;
            num_coins++;
        }
        // if change_owed_int is subtracted by 10, then 10 cents is removed from change_owed_int and num_coins is incremented by 1
        else if
        (change_owed_int - 10 >= 0)
        {
            change_owed_int -= 10;
            num_coins++;
        }
        // if change_owed_int is subtracted by 5, then 5 cents is removed from change_owed_int and num_coins is incremented by 1
        else if
        (change_owed_int - 5 >= 0)
        {
            change_owed_int -= 5;
            num_coins++;
        }
        // else change_owed_int is subtracted by 1, then 1 cent is removed from change_owed_int and num_coins is incremented by 1
        else
        {
            change_owed_int -= 1;
            num_coins++;
        }
    }

    printf("%d\n", num_coins);

}