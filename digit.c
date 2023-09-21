#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    long n;
    do
    {
        n = get_int("Number: ");
    }
    while (isdigit(n));

    if (n < 0)
    {
        n = n * -1;
    }

    while (n > 10)
    {
        n = n / 10;
    }
    long first = n;
    printf("%ld\n", n);
}