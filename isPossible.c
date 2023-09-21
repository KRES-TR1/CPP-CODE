#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    long a, b, c;
    int n = 0;
    a = get_long("A: ");
    b = get_long("B: ");
    c = get_long("C: ");

    double z = (double)a / (double)b;
    double x = (double)b / (double)a;
    if (a + b == c || a * b == c || a - b == c || b + a == c || b * a == c || b - a == c)
    {
        printf("Possible\n");
        return true;
    }
    else if (a / b == c || b / a == c)
    {
        if (floor(z) == z)
        {
            printf("Possible\n");
            return true;
        }
        else if (floor(x) == x)
        {
            printf("Possible\n");
            return true;
        }
        else
        {
            printf("Not possible\n");
            return false;
        }
    }
    else
    {
        printf("Not possible\n");
        return false;
    }
}
