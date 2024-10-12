#include "iter.hpp"


void print2(const int &value) {
	std::cout << value << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter<int>(intArray, 5, print<int>);
	std::cout <<std::endl;
	std::cout << "intArray: ";
	iter(intArray, 5, print2);
	std::cout <<std::endl;
	std::cout << "floatArray: ";
	iter(floatArray, 5, print<float>);
	std::cout <<std::endl;
	std::cout << "stringArray: ";
	iter(stringArray, 5, print<std::string>);
	std::cout <<std::endl;
	return 0;
}