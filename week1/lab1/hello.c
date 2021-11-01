#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // initialize string variable
    string name = get_string("What is your name: "); 
    
    // print name variable 
    printf("hello, %s\n", name); 
}