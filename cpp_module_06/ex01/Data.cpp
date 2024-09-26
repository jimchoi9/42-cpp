#include "Data.hpp"

Data::Data() : data("default") {}

Data::Data(const std::string &data) : data(data) {}

Data::Data(const Data &src) : data(src.data) {}

Data::~Data() {}	

Data &Data::operator=(const Data &src) {
	if (this != &src) {
		const_cast<std::string &>(data) = src.data;
	}
	return *this;
}

const std::string &Data::getData() {
	return data;
}