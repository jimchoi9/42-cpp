# include <string>
# include <iostream>
#include "PhoneBook.hpp"
#include <iomanip>


int main()
{
	// PhoneBook phoneBook;
	// phoneBook.phone_book();

	std::cout << std::setw(10);
	std::cout << "Name" << "|"<<std::setw(15);
    std::cout << "Number" <<"|"<< std::endl;

	std::string str;
	str = "phone";
	std::cout << str.substr(0, 10) << "|" << std::endl;
	str.resize(3);
	str.resize(6, '+');
	size_t len = str.size();
	std::cout << str << std::endl;

    return 0;


}