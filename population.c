#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // prompt for start size
    int n;
    do
    {
        n = get_int("Start population? ");
    }
    while (n < 9);

    // prompt for end size
    int m;
    do
    {
        m = get_int("End population? ");
    }
    while (m < n);

    // prompt calulating
    int y = 0;
    while (n < m)
    {
        n = n + (n / 3) - (n / 4);
        y++;
    }
    
    // print
    if (m <= n)
    {
        printf("Years: %i\n", y);
    }
}