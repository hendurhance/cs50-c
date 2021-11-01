#include <stdio.h>
#include <cs50.h>



int main(void)
{
    // prompt user for start population size
    int start_pop;
    do
    {
        start_pop = get_int("Start size: ");
    }
    while (start_pop < 9); // input should be at least 9

    // prompt user for end population size
    int end_pop;
    do
    {
        end_pop = get_int("End size: ");
    }
    while (end_pop < start_pop); // input should be greater than start_pop

    // initialize variables
    int years, gain, loss;
    years = 0; // number of years is 0

    // Calculate population growth where start_pop is less than end_pop
    // gain is start_pop / 3 and loss is start_pop / 4
    while (start_pop < end_pop)
    {
        gain = start_pop / 3; // gain is starting population / 3
        loss = start_pop / 4; // loss is starting population / 4
        start_pop += gain - loss; // starting poplation is starting population + gain - loss
        years++;
    }


    // Print out the number of years to reach threshold
    printf("Years: %i\n", years);

}