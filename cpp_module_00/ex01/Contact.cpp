#include "Contact.hpp"

bool Contact::set_first_name(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "First_name is empty" << std::endl;
		return false;
	}
	first_name = str;
	return true;
}
bool Contact::set_last_name(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "Last_name is empty" << std::endl;
		return false;
	}
	last_name = str;
	return true;
}
bool Contact::set_nick_name(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "Nick_name is empty" << std::endl;
		return false;
	}
	nick_name = str;
	return true;
}
bool Contact::set_phone_number(const std::string &str)
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
		std::cout << "Phone_number is good" << std::endl;
	phone_number = str;
	return true;
}

bool Contact::set_secret(const std::string &str)
{
	if (str.empty())
	{
		std::cout << "Secret is empty" << std::endl;
		return false;
	}
	secret = str;
	return true;
}

