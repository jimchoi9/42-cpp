#include "Serializer.hpp"

int main() {

	Data data;
	uintptr_t uintPtr = Serializer::serialize(&data);

	Data* dataPtr = Serializer::deserialize(uintPtr);

	std::cout << "data : " << dataPtr->getData() << std::endl;

	Data data2("hello");
	uintptr_t uintPtr2 = Serializer::serialize(&data2);

	Data* dataPtr2 = Serializer::deserialize(uintPtr2);

	std::cout << "data : " << dataPtr2->getData() << std::endl;

	return 0;
}