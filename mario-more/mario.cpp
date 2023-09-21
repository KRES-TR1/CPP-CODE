#include <iostream>

int get_height();
void print_block(int height);

int main()
{
    int height = get_height();
    print_block(height);
    return 0;
}

int get_height()
{
    int height = 0;
    do
    {
        std::cout << "Height? " << std::endl;
        std::cin >> height;
    } while (height < 1 || height > 8);
    return height;
}

void print_block(int height)
{
    for (int i = 1; i <= height; i++)
    {
        int space = height - i;
        for (int k = 0; k < space; k++)
        {
            std::cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            std::cout << "#";
        }
        std::cout << "  ";
        for (int n = 0; n < i; n++)
        {
            std::cout << "#";
        }
        std::cout << std::endl;
    }
}
