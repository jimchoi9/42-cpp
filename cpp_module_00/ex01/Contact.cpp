#include "Contact.hpp"


Contact::Contact()
: first_name(""), last_name(""), nick_name(""), phone_number(""), secret(""){}

std::string Contact::get_first_name()
{return first_name;}

std::string Contact::get_last_name()
{return last_name;}

std::string Contact::get_nick_name()
{return nick_name;}

std::string Contact::get_phone_number()
{return phone_number;}

std::string Contact::get_secret()
{return secret;}

bool Contact::set_first_name(const std::string &str)
{
	if (str.empty())
	{
		return false;
	}
	bool empty = true;
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]))
			empty = false;
	}
	if (empty)
		return false;
	first_name = str;
	return true;
}
bool Contact::set_last_name(const std::string &str)
{
	if (str.empty())
	{
		return false;
	}
	bool empty = true;
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]))
			empty = false;
	}
	if (empty)
		return false;
	last_name = str;
	return true;
}
bool Contact::set_nick_name(const std::string &str)
{
	if (str.empty())
	{
		return false;
	}
	bool empty = true;
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]))
			empty = false;
	}
	if (empty)
		return false;
	nick_name = str;
	return true;
}
bool Contact::set_phone_number(const std::string &str)
{
	if (str.empty())
	{
		return false;
	}
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
        {
            std::cout << "Invalid phone number" << std::endl;
            return false;
        }
	}
	phone_number = str;
	return true;
}

bool Contact::set_secret(const std::string &str)
{
	if (str.empty())
	{
		return false;
	}
	bool empty = true;
	for(size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]))
			empty = false;
	}
	if (empty)
		return false;
	secret = str;
	return true;
}

