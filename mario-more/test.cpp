#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Height? ");
    } while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        int k;
        int j;
        int l;
        int spaces = height - i;
        for (k = 0; k < spaces; k++)
        {
            printf(" ");
        }
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf ("  ");
        for (l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
