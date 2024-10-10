#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


#include <iostream>
#include <cctype>

class ScalarConverter {

	public:
	static void convert(const std::string str);

	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter&a);
		ScalarConverter(const ScalarConverter&a);
	};

#endif