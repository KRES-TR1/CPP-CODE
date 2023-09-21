#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");
    int width = get_int("Width: ");
    int height = get_int("Height: ");

    printf("Rectangle 0 [x= %i, y= %i, width= %i, height= %i]\n", x, y, width, height);

    int w = x + width;
    int h = y + height;
    int w1 = h + width;
    int h1 = w + height;

    printf("Area rectangle 0: %ix%i\n", w, h);

    int x1 = get_int("X1: ");
    int y1 = get_int("Y1: ");
    int width1 = get_int("Width1: ");
    int height1 = get_int("Height1: ");

    printf("Rectangle 1 [x= %i, y= %i, width= %i, height= %i]\n", x1, y1, width1, height1);

    int n = x1 + width1;
    int m = y1 + height1;
    int n1 = m + width1;
    int m1 = n + height1;

    printf("Area rectangle 1: %ix%i\n", n, m);

if ((x == 0 && y == 0) || (x1 == 0 && y1 == 0))
{
    printf("Invaild number!\n");
    return 1;
}
else if(x == width || y == height || x1 == width1 || y1 == height1)
{
    printf("Not Rectangle\n");
    return 1;
}
    if (x <= x1 <= w || x1 <= x <= n)
    {
        if (y <= y1 <= h || y1 <= y <= m || y <= y1 >= h || y1 <= y >= m)
        {
            printf("Rectangle intersection\n");
        }
        else
        {
            printf("Not Rectangle intersection\n");
        }
    }
    else if (x <= x1 >= w || x1 <= x >= n)
    {
        if (y <= y1 <= h || y1 <= y <= m || y <= y1 >= h || y1 <= y >= m)
        {
            printf("Rectangle intersection\n");
        }
        else
        {
            printf("Not Rectangle intersection\n");
        }
    }

}