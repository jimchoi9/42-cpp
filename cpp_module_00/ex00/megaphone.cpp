#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    
    std::string str;
    for (int i = 1; i < argc; i++)
    {
        str = argv[i];
        for(int j = 0; j < (int)str.length(); j++)
        {
            std::cout << (char)std::toupper(str[j]);
        }
        if (argv[i + 1])
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}