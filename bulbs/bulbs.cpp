#include <iostream>
#include <string>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main()
{
    std::string message;
    std::cout << "Message: ";
    std::getline(std::cin, message);
    int n = message.length();

    for (int i = 0; i < n; i++)
    {
        int h = 7;
        int b[] = {0, 0, 0, 0, 0, 0, 0, 0};
        char ch = message[i];

        while (ch > 0)
        {
            int bit = ch % 2;
            ch = ch / 2;
            b[h] = bit;
            h--;
        }

        for (int j = 0; j < 8; j++)
        {
            print_bulb(b[j]);
        }

        std::cout << std::endl;
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        std::cout << "\u25CF";
    }
    else if (bit == 1)
    {
        // Light emoji
        std::cout << "\U0001F31E";
    }
}
