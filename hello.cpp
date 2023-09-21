#include <iostream>
#include <string>

int main()
{
    // Asks user for their name
    std::string name;
    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    // Prints hello and the user's name
    std::cout << "Hello, " << name << std::endl;

    return 0;
}
