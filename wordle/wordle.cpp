#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <string>

#define LISTSIZE 1000
#define EXACT 2
#define CLOSE 1
#define WRONG 0

#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

std::string get_guess(int wordsize);
int check_word(const std::string& guess, int wordsize, int status[], const std::string& choice);
void print_word(const std::string& guess, int wordsize, int status[]);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./wordle wordsize" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            std::cout << "Usage: ./wordle wordsize" << std::endl;
            return 1;
        }
    }

    int wordsize = 0;

    if (atoi(argv[1]) > 5 || atoi(argv[1]) < 8)
    {
        wordsize = atoi(argv[1]);
    }
    else
    {
        std::cout << "Error: wordsize must be either 5, 6, 7, or 8" << std::endl;
        return 1;
    }

    std::string wl_filename = std::to_string(wordsize) + ".txt";
    std::ifstream wordlist(wl_filename);
    if (!wordlist)
    {
        std::cout << "Error opening file " << wl_filename << std::endl;
        return 1;
    }

    std::string options[LISTSIZE];

    for (int i = 0; i < LISTSIZE; i++)
    {
        wordlist >> options[i];
    }

    srand(time(NULL));
    std::string choice = options[rand() % LISTSIZE];

    int guesses = wordsize + 1;
    bool won = false;

    std::cout << GREEN << "This is WORDLE50" << RESET << std::endl;
    std::cout << "You have " << guesses << " tries to guess the " << wordsize << "-letter word I'm thinking of" << std::endl;

    for (int i = 0; i < guesses; i++)
    {
        std::string guess = get_guess(wordsize);
        int status[wordsize];

        for (int j = 0; j < wordsize; j++)
        {
            status[j] = 0;
        }

        int score = check_word(guess, wordsize, status, choice);

        std::cout << "Guess " << i + 1 << ": ";
        print_word(guess, wordsize, status);

        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    if (won)
    {
        std::cout << "you won!" << std::endl;
    }
    else
    {
        std::cout << "you lose!" << std::endl;
        std::cout << "the word was: " << choice << std::endl;
    }

    return 0;
}

std::string get_guess(int wordsize)
{
    std::string guess;

    do
    {
        std::cout << "Input a " << wordsize << "-letter word: ";
        std::cin >> guess;
    } while (guess.length() != static_cast<unsigned int>(wordsize));

    return guess;
}

int check_word(const std::string& guess, int wordsize, int status[], const std::string& choice)
{
    int score = 0;

    for (int i = 0; i < wordsize; i++)
    {
        for (int j = 0; j < wordsize; j++)
        {
            if (guess[i] == choice[j])
            {
                if (i == j)
                {
                    score += EXACT;
                    status[i] += EXACT;
                    break;
                }
                else
                {
                    score += CLOSE;
                    status[i] += CLOSE;
                }
            }
        }
    }

    return score;
}

void print_word(const std::string& guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, guess[i]);
        }
        else
        {
            printf(RED "%c" RESET, guess[i]);
        }
    }

    printf("\n");
    return;
}
