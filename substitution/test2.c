#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool check_duli(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }
    if (!check_duli(argv[1]))
    {
        printf("Key must contain 26 unique characters.\n");
    }
}

bool check_duli(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < length; i++)
    {
        key[i] = toupper(key[i]);
        if (!isalpha(key[i]))
        {
            return false;
        }
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j])
            {
                return false;
            }
        }
    }
    return true;
}
