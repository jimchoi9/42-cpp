#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
	(void)src;
}
ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src) {
	(void)src;
	return *this;
}

uintptr_t ScalarConverter::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* ScalarConverter::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}