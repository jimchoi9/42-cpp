#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP


#include <iostream>
#include <string>
#include "Contact.hpp"


class PhoneBook 
{
	private:
		Contact contact[8];
		int index;
	public:
		PhoneBook()
		{index = 0;}
		void phone_book();
		bool add_contact();
		std::string input_info();
		void display(int index);

};

#endif