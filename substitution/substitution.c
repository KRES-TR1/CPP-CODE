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
        return 1;
    }

    else if (strlen(argv[1]) == 26)
    {
        string key = argv[1];
        char input[26];

        for (int k = 0; k < strlen(argv[1]); k++)
        {
            input[k] = key[k];
            if (isdigit(input[k]))
            {
                printf("Usage: ./substitution key\n");
                return 0;
            }
            else if (!check_duli(argv[1]))
            {
                printf("Key must contain 26 unique characters.\n");
                return 1;
            }
            string plaintext = get_string("Plaintext: ");
            printf("ciphertext: ");
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                input[j] = key[j];
            }
            int l = 0;
            for (l = 0; l < strlen(plaintext); l++)
            {
                int index = 0;

                if (isupper(plaintext[l]))
                {
                    index = plaintext[l] - 65;
                    plaintext[l] = input[index];
                    printf ("%c", toupper(plaintext[l]));

                }
                else if (islower(plaintext[l]))
                {
                    index = plaintext[l] - 97;
                    plaintext[l] = input[index];
                    printf("%c", tolower(plaintext[l]));
                }
                else
                {
                    printf("%c", plaintext[l]);
                }
            }
            printf("\n");
            return 0;
        }

    }
    else if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (strlen(argv[1]) > 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
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