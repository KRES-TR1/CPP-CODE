#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string strings[] = {"Battle ship", "Race car"};

    string s = get_string("Strings ");
    for(int i = 0; i < 2; i++)
    {
        if (strcmp(strings[i],s) == 0)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}