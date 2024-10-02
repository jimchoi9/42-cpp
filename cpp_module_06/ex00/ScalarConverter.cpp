#include "ScalarConverter.hpp"


#include <string>

bool isNan(std::string value)
{
	if (value == "nan"|| value == "nanf")
		return true;
	else
		return false;
}

void isChar(std::string str) {
	if (str.size() != 1 || std::isdigit(str[0]))
		return ;
	char c = str[0];
	

	std::cout <<"char: "<< static_cast<char>(c) << std::endl;
	std::cout <<"int: "<< static_cast<int>(c) << std::endl;
	std::cout <<"float: "<< static_cast<float>(c) <<".0f"<< std::endl;
	std::cout <<"double: "<< static_cast<double>(c) <<".0"<< std::endl;

}
void isInt(std::string str) {
	for(size_t i = 0; i < str.size(); i++) {
		if (i > 10)
			return ;
		if (!(std::isdigit(str[i])) && !(str[i] == '-' || str[i] == '+'))
			return ;
	}
	int num = std::atoi(str.c_str());
	std::cout <<"char: ";
	if (num < 0 || num > 127)
		std::cout << "impossible" << std::endl;
	else if(num <= 0 || num >= 127)
		std::cout << "Non displayable" << std::endl;
	else
	std::cout << static_cast<char>(num) << std::endl;
	std::cout <<"int: "<<  static_cast<int>(num) << std::endl;
	std::cout <<"float: "<< static_cast<float>(num) <<".0f"<< std::endl;
	std::cout <<"double: "<< static_cast<double>(num) <<".0"<< std::endl;

}
void isDouble(std::string str) {
	// int check = 0;
	for(size_t i = 0; i < str.size(); i++) {
		if (i > 15)
			return ;
		if (!std::isdigit(str[i]) && str[i] != '.' )
			return ;
	}
}
void isFloat(std::string str){
	for(size_t i = 0; i < str.size(); i++) {
		if (!std::isdigit(str[i]) || i > 10)
			return ;
	}
} 

std::string parsing(std::string str) {
	int neg = 1;

	std::string temp = str;
	for(size_t i = 0; i < str.size(); i++) {
		if (str[i] == '-')
			neg = -1;
		if (str[i] == '+' || str[i] == '-')
			str = str.erase(i);
		else 
			break;
		
	}
	if (str.size() == 0)
		return temp;

	return str;
}

void ScalarConverter::convert(const std::string str) {
	
	// isChar(str);
	isInt(str);
}

ㅏ\ㅇㅣ레이저를 사요오하면 문자열의 앞 부분을 제거할  수  있습니다. 예예를  들들어  할  수  하하 특정위치에서 시작하는 문자열을 예를들어 
어어... 문문자열 ㄱ=캐스팅 질문 함수 포인터 사용법 지난 30일 찾ㅊ마조자 포인터변환문제 내부 예외클래스 입출ㅇ력연산자 오	버버로로딩  이이소소민민은  솔솔직직히 최강이라 생각한다.