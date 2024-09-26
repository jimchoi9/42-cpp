#include "ScalarConverter.hpp"

int main() {

	Data data;
	uintptr_t uintPtr = ScalarConverter::serialize(&data);

	Data* dataPtr = ScalarConverter::deserialize(uintPtr);

	std::cout << "data : " << dataPtr->getData() << std::endl;

	Data data2("hello");
	uintptr_t uintPtr2 = ScalarConverter::serialize(&data2);

	Data* dataPtr2 = ScalarConverter::deserialize(uintPtr2);

	std::cout << "data : " << dataPtr2->getData() << std::endl;

	return 0;
}