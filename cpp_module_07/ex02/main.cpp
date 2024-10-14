#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10

// void check_leaks() {
// 	system("leaks ex02");
// }


int main(int, char**)
{
	// atexit(check_leaks);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[0] = 0;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }


    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " " ;
    }
        std::cout << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << numbers[i] << " ";
    }
	std::cout << std::endl;
	
    delete [] mirror;

	std::cout << "================================================================\n";

	try {

	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;
	std::cout << "empty[0]" << empty[0] << std::endl;
	} catch (const std::out_of_range &e) {
		std::cerr << e.what() << std::endl;
	}

	Array<int> arr(5);
	std::cout << "Array size: " << arr.size() << std::endl;
	arr[0] = 42;
	Array<int> copy(arr);
	arr[1] = 42;

	arr = copy;
	arr[2] = 42;

	std::cout << " arr[0] " << arr[0] << std::endl;
	std::cout << " arr[1] " << arr[1] << std::endl;
	std::cout << " arr[2] " << arr[2] << std::endl;
    std::cout << "copy[0] " << copy[0] << std::endl;
    std::cout << "copy[1] " << copy[1] << std::endl;
    std::cout << "copy[2] " << copy[2] << std::endl;


    Array<int> arr2(10);

    return 0;
}