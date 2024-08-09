#include "Contact.hpp"

bool Contact::set_first_name(std::string &str)
{
	if (str.empty())
	{
		std::cout << "First_name is empty" << std::endl;
		return false;
	}
	first_name = str;
	return true;
}
bool Contact::set_last_name(std::string &str)
{
	if (str.empty())
	{
		std::cout << "Last_name is empty" << std::endl;
		return false;
	}
	last_name = str;
	return true;
}
bool Contact::set_nick_name(std::string &str)
{
	if (str.empty())
	{
		std::cout << "Nick_name is empty" << std::endl;
		return false;
	}
	nick_name = str;
	return true;
}
bool Contact::set_phone_number(std::string &str)
{
	if (str.empty())
	{
		std::cout << "Phone_number is empty" << std::endl;
		return false;
	}
	// if (std::atoi(str.c_str()) == 0 && !std::strcmp(str.c_str(), "0"))
	if (std::atoi(str.c_str()) == 0)
	{
		std::cout << "Invalid phone number" << std::endl;
			return false;
	}
	phone_number = str;
	return true;
}

bool Contact::set_secret(std::string &str)
{
	if (str.empty())
	{
		std::cout << "Secret is empty" << std::endl;
		return false;
	}
	secret = str;
	return true;
}

