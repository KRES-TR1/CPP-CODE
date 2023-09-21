#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you argee?");
    if (c == 'y' || c == 'Y')
    {
        printf("Argeed.\n");
    }
    if (c == 'n' || c == 'N')
    {
        printf("Disargeed.\n");
    }
}