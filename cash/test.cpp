#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents;
    do
    {
        cents = get_int("How much? \n");
    }
    while (cents < 1 );
}
