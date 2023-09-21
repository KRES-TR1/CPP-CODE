#include <iostream>
#include <cstring>
#include <cctype>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const std::string& word);

int main()
{
    // Get input words from both players
    std::string word1;
    std::cout << "Player 1: ";
    std::getline(std::cin, word1);

    std::string word2;
    std::cout << "Player 2: ";
    std::getline(std::cin, word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        std::cout << "Player 1 wins!" << std::endl;
    }
    else if (score2 > score1)
    {
        std::cout << "Player 2 wins!" << std::endl;
    }
    else
    {
        std::cout << "Tie!" << std::endl;
    }

    return 0;
}

int compute_score(const std::string& word)
{
    int total = 0;
    for (char c : word)
    {
        if (std::isalpha(c) != 0)
        {
            char uppercaseC = std::toupper(c);
            int ascii = static_cast<int>(uppercaseC);
            int index = ascii - 65;
            total += POINTS[index];
        }
    }
    return total;
}
