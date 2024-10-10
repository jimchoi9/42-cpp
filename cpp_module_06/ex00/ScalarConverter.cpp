#include "ScalarConverter.hpp"


#include <string>

enum TYPE{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	STRING,
	DEFAULT,
};

enum NANTYPE {
	_NAN,
	INF,
	NEG_INF,
	POS_INF,
	NORMAL,
};



static int dot = 0;
static int f = 0;
static TYPE strType = DEFAULT;
static NANTYPE nonType = NORMAL;




bool isNan(std::string value)
{
	if (value == "nan"|| value == "NAN" ) 
	{
		nonType = _NAN;
		strType = DOUBLE;
		return true;
	}
	else if (value == "inf" || value == "INF")
	{
		nonType = INF;
		strType = DOUBLE;
		return true;
	}
	else if (value == "-inf" || value == "-INF" )
	{
		nonType = NEG_INF;
		strType = DOUBLE;
		return true;
	}
	else if (value == "+inf" || value == "+INF" )
	{
		nonType = POS_INF;
		strType = DOUBLE;
		return true;
	}
	else if (value == "nanf"|| value == "NANf" ) 
	{
		nonType = _NAN;
		strType = FLOAT;
		return true;
	}
	else if (value == "inff" || value == "INFF")
	{
		nonType = INF;
		strType = FLOAT;
		return true;
	}
	else if (value == "-inff" || value == "-INFF" )
	{
		nonType = NEG_INF;
		strType = FLOAT;
		return true;
	}
	else if (value == "+inff" || value == "+INFF" )
	{
		nonType = POS_INF;
		strType = FLOAT;
		return true;
	}

	else
		return false;
}

bool isChar(std::string str) {
	if (str.size() != 1 || std::isdigit(str[0]))
		return false;
	return true;

}
bool isInt(std::string str) {
	if (str[0] == '-')
		str.erase(0, 1);
	if (str.size() > 10)
			return false;
	if (dot || f)
		return false;
	
	return true;

}
bool isDouble(std::string str) {

	if (str[0] == '-')
		str.erase(0, 1);
	if (str.size() > 15)
		return false;
	if (!dot || f)
		return false;
	if (str[str.size() - 1] == '.')
		return false;
	return true;
}
bool isFloat(std::string str){
	if (str[0] == '-')
		str.erase(0, 1);
	if (str.size() > 8) // f포함
		return false;
	if (!dot || !f)
		return false;
	if (str[str.size() - 2] == '.')
		return false;
	return true;
} 

void detectType(std::string &str) {
	if (strType == DEFAULT && nonType == NORMAL)
	{
		if (isChar(str))
			strType = CHAR;
		else if (isInt(str))
			strType = INT;
		else if (isDouble(str))
			strType = DOUBLE;
		else if (isFloat(str))
			strType = FLOAT;
		else
			strType = STRING;
	}
}

std::string parsing(std::string str) {
	int neg = 0;
	int erase = 0;


	std::string temp = str;
	if (isNan(str))
		return str;


	for (size_t i = 0; (str[i] == '-' || str[i] == '+'); i ++)
	{
		if (str[i] == '-')
		{
			neg ++;
			erase = 1;
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			neg --;
			erase = 1;
		}
		if (erase)
		{
			str.erase(i, 1);
			erase = 0;
			i--;
		}
	}
	size_t size = str.size();
	for(size_t i = 0; i < size; i++) {

		if (std::isspace(str[i]))
			erase = 1;
		else if (str[i] == '.')
			dot++;
		else if (str[i] == 'f')
			f++;
		else if (i > 0 && !isdigit(str[i]))
		{
			strType = STRING;
		} 
		if (erase)
		{
			str.erase(i, 1);
			i--;
			size--;
			erase = 0;
		}
	}
	if (str.size() == 0 || dot > 1 || f > 1)
	{
		strType = STRING;
		return temp;
	}
	else if (neg > 0)
		str = "-" + str;
	return str;
}


void printChar(std::string str) {
	char c = str[0];
	std::cout <<"char: ";
	if (c < 0 || c > 127)
		std::cout << "impossible" << std::endl;
	else if(c <= 0 || c >= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
	std::cout <<"int: "<<  static_cast<int>(c) << std::endl;
	std::cout <<"float: "<< static_cast<float>(c) <<".0f"<< std::endl;
	std::cout <<"double: "<< static_cast<double>(c) <<".0"<< std::endl;
}

void printInt(std::string str) {
	int num = std::atoi(str.c_str());
	std::cout <<"char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else if(num <= 0 || num >= 127)
		std::cout << "Non displayable" << std::endl;
	else
	std::cout << static_cast<char>(num) << std::endl;
	std::cout <<"int: "<<  num << std::endl;
	std::cout <<"float: "<< static_cast<float>(num) <<".0f"<< std::endl;
	std::cout <<"double: "<< static_cast<double>(num) <<".0"<< std::endl;
}

void printDouble(std::string str) {
	
	if (nonType != NORMAL)
	{
		std::string nonStr[] = {"nan", "inf", "-inf", "+inf"};
		std::cout << "char: "<< "impossible" << std::endl;
		std::cout <<"int: "<<  "impossible" << std::endl;
		std::cout <<"float: "<< nonStr[nonType] << "f" << std::endl;
		std::cout <<"double: "<< nonStr[nonType] << std::endl;
		return ;
	}
	double num = std::atof(str.c_str());
	std::cout <<"char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else if(num <= 0 || num >= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(num) << std::endl;
	std::cout <<"int: "<<  static_cast<int>(num) << std::endl;
	std::cout <<"float: " << num;
	double temp = num - static_cast<int>(num);
	if (temp == 0)
		std::cout << ".0f"<< std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout <<"double: "<< static_cast<double>(num);
	if (temp == 0)
		std::cout<< ".0" << std::endl;
	else
	std::cout<< std::endl;
}

void printFloat(std::string str) {
	if (nonType != NORMAL)
	{
		std::string nonStr[] = {"nan", "inf", "-inf", "+inf"};
		std::cout << "char: "<< "impossible" << std::endl;
		std::cout <<"int: "<<  "impossible" << std::endl;
		std::cout <<"float: "<< nonStr[nonType] << "f" << std::endl;
		std::cout <<"double: "<< nonStr[nonType] << std::endl;
		return ;
	}
	float num = std::atof(str.c_str());
	std::cout <<"char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else if(num <= 0 || num >= 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << static_cast<char>(num) << std::endl;
	std::cout <<"int: "<<  static_cast<int>(num) << std::endl;
	std::cout <<"float: " << num;
	float temp = num - static_cast<int>(num);
	if (temp == 0)
		std::cout << ".0f"<< std::endl;
	else
		std::cout << "f" << std::endl;
	std::cout <<"double: "<< static_cast<double>(num);
	if (temp == 0)
		std::cout<< ".0" << std::endl;
	else
	std::cout<< std::endl;
}

void printString(std::string str) {
	(void)str;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string str) {
	std::string tempStr = parsing(str);
	detectType(tempStr);

	void (*printType[])(std::string) = {&printChar, &printInt, &printDouble, &printFloat, &printString};
	printType[strType](tempStr);

}


