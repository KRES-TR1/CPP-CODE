#include <iostream>
#include <string>

int main()
{
    long long cc_number;
    std::cout << "Number: ";
    std::cin >> cc_number;

    int digit1 = 0;
    int digit2 = 0;
    int number_of_digits = 0;
    int sum_odds_2x = 0;
    int sum_evens = 0;

    while (cc_number > 0)
    {
        digit2 = digit1;
        digit1 = cc_number % 10;

        if (number_of_digits % 2 == 0)
        {
            sum_evens += digit1;
        }
        else
        {
            int multiple = 2 * digit1;
            sum_odds_2x += (multiple / 10) + (multiple % 10);
        }

        cc_number /= 10;
        number_of_digits++;
    }

    bool is_valid = (sum_evens + sum_odds_2x) % 10 == 0;
    int first_two_digits = (digit1 * 10) + digit2;

    if (digit1 == 4 && number_of_digits >= 13 && number_of_digits <= 16 && is_valid)
    {
        std::cout << "VISA" << std::endl;
    }
    else if ((first_two_digits == 34 || first_two_digits == 37) && number_of_digits == 15 && is_valid)
    {
        std::cout << "AMEX" << std::endl;
    }
    else if (first_two_digits >= 51 && first_two_digits <= 55 && number_of_digits == 16 && is_valid)
    {
        std::cout << "MASTERCARD" << std::endl;
    }
    else
    {
        std::cout << "INVALID" << std::endl;
    }

    return 0;
}
