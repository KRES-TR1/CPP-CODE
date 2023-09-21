#include <iostream>
#include <cstring>
#include <cctype>

bool check_duli(std::string key);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./substitution key" << std::endl;
        return 1;
    }
    else if (strlen(argv[1]) == 26)
    {
        std::string key = argv[1];
        char input[26];

        for (int k = 0; k < strlen(argv[1]); k++)
        {
            input[k] = key[k];
            if (isdigit(input[k]))
            {
                std::cout << "Usage: ./substitution key" << std::endl;
                return 0;
            }
            else if (!check_duli(argv[1]))
            {
                std::cout << "Key must contain 26 unique characters." << std::endl;
                return 1;
            }
            std::string plaintext;
            std::cout << "Plaintext: ";
            std::getline(std::cin, plaintext);
            std::cout << "ciphertext: ";
            for (int j = 0; j < strlen(argv[1]); j++)
            {
                input[j] = key[j];
            }
            int l = 0;
            for (l = 0; l < plaintext.length(); l++)
            {
                int index = 0;

                if (isupper(plaintext[l]))
                {
                    index = plaintext[l] - 65;
                    plaintext[l] = input[index];
                    std::cout << static_cast<char>(toupper(plaintext[l]));
                }
                else if (islower(plaintext[l]))
                {
                    index = plaintext[l] - 97;
                    plaintext[l] = input[index];
                    std::cout << static_cast<char>(tolower(plaintext[l]));
                }
                else
                {
                    std::cout << plaintext[l];
                }
            }
            std::cout << std::endl;
            return 0;
        }
    }
    else if (strlen(argv[1]) < 26)
    {
        std::cout << "Key must contain 26 characters." << std::endl;
        return 1;
    }
    else if (strlen(argv[1]) > 26)
    {
        std::cout << "Usage: ./substitution key" << std::endl;
        return 1;
    }
}

bool check_duli(std::string key)
{
    int length = key.length();
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
