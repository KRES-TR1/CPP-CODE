#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int n = get_int("How many line?: \n");
    int m = n;
    int a = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            printf(".");
        }
        for(int k = 0; k < a ; k++)
        {
            printf("%i", a);
        }
            printf("\n");
        a++;
        m--;
    }
}