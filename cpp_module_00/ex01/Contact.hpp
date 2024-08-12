
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_number;
		std::string secret;
	public:
		Contact();
		bool set_first_name(const std::string &str);
		bool set_last_name(const std::string &str);
		bool set_nick_name(const std::string &str);
		bool set_phone_number(const std::string &str);
		bool set_secret(const std::string &str);
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nick_name();
		std::string get_phone_number();
		std::string get_secret();
};

#endif