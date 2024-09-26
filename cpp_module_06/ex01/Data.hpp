#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	public:
		Data();
		Data(const std::string &data);
		Data(const Data &src);
		~Data();
		Data &operator=(const Data &src);
		const std::string &getData();
	private:
		const std::string data;
};

	

#endif
