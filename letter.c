#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 0;
    }
    int arry[26];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if(strlen(argv[1]) == 0)
        {
            printf("%c",arry[i]);
        }
        if (islower(argv[1][i]))
        {
            argv[1][i] = argv[1][i] - 97;
            arry[i]++;
            printf("%i", arry[i]);
        }
        else if (isupper(argv[1][i]))
        {
            argv[1][i] = argv[1][i] - 65;
            arry[i]++;
            printf("%i", arry[i]);
        }
    }
    printf("\n");
}
