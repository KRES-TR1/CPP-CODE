#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./caesar key" << std::endl;
        return 1;
    }

    int k = std::atoi(argv[1]);

    if (k < 0)
    {
        std::cout << "Usage: ./caesar key" << std::endl;
        return 2;
    }

    std::string text;
    std::cout << "Text: ";
    std::getline(std::cin, text);

    std::cout << "ciphertext: ";

    for (int i = 0, n = text.length(); i < n; i++)
    {
        if (std::isalpha(text[i]))
        {
            if (std::isupper(text[i]))
            {
                char cipher_num_capital = ((text[i] - 'A' + k) % 26) + 'A';
                std::cout << cipher_num_capital;
            }

            if (std::islower(text[i]))
            {
                char cipher_num_small = ((text[i] - 'a' + k) % 26) + 'a';
                std::cout << cipher_num_small;
            }
        }
        else
        {
            std::cout << text[i];
        }
    }

    std::cout << std::endl;
    return 0;
}
