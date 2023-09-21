#include <stdio.h>
#include <cs50.h>

const int n = 3;
float average(int lenght, int array[]);

int main(void)
{
    int scores[n];
    for (int i = 0; i < n ; i++)
    {
        scores[i] = get_int("Scores? ");
    }
    printf("Average: %f\n", average(n, scores));
}

float average(int lenght, int array[])
{
    int sum = 0;
    for (int i = 0; i < lenght; i++)
    {
        sum = sum + array[i];
    }
    return sum / (float) lenght;
}
