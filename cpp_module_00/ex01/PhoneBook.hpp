#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"


class PhoneBook 
{
	private:
		Contact contact[8];
		int index;
	public:
		PhoneBook();
		void phone_book();
		bool add_contact();
		std::string input_info(std::string str);
		void display();
		void print_substr(const std::string str);
		bool is_print_string(const std::string str);
};

#endif 