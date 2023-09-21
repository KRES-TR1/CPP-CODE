#include <iostream>
#include <string>
#include <cmath>

int count_letters(const std::string& text);
int count_words(const std::string& text);
int count_sentences(const std::string& text);

int main()
{
    std::string input;
    std::cout << "Text: ";
    std::getline(std::cin, input);

    int num_letters = count_letters(input);
    int num_words = count_words(input);
    int num_sentences = count_sentences(input);

    double L = 100 * (static_cast<double>(num_letters) / static_cast<double>(num_words));
    double S = 100 * (static_cast<double>(num_sentences) / static_cast<double>(num_words));

    int index = std::round(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        std::cout << "Grade 16+" << std::endl;
    }
    else if (index < 1)
    {
        std::cout << "Before Grade 1" << std::endl;
    }
    else
    {
        std::cout << "Grade " << index << std::endl;
    }

    return 0;
}

int count_letters(const std::string& text)
{
    int total_letters = 0;
    for (char c : text)
    {
        if (std::isalpha(c))
        {
            total_letters++;
        }
    }
    return total_letters;
}

int count_words(const std::string& text)
{
    int total_words = 1;
    for (char c : text)
    {
        if (c == ' ')
        {
            total_words++;
        }
    }
    return total_words;
}

int count_sentences(const std::string& text)
{
    int total_sentences = 0;
    for (char c : text)
    {
        if (c == '.' || c == '!' || c == '?')
        {
            total_sentences++;
        }
    }
    return total_sentences;
}
