#include "PhoneBook.hpp"

bool PhoneBook::is_print_string(std::string str)
{
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!isprint(str[i]))
			return false;
	}
	return true;
}

std::string PhoneBook::input_info(std::string str)
{
	std::string input;
	while (true)
	{
		std::cout << str;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
            std::cin.clear();
            clearerr(stdin);
			std::cout << std::endl;
			continue;
        }
		if (!is_print_string(input))
			continue;
		break;
	}
	return (input);
}

bool PhoneBook::add_contact()
{
	std::string number;
	index = index % 8;

    contact[index].set_first_name(input_info("Enter first name : "));
    contact[index].set_last_name(input_info("Enter last name : "));
    contact[index].set_nick_name(input_info("Enter nick name : "));
	while(true)
	{
		if (contact[index].set_phone_number(input_info("Enter phone number : ")))
			break;
	}
    contact[index].set_secret(input_info("Enter secret : "));
	index ++;
	return (true);
}

void PhoneBook::print_substr(const std::string str)
{
	std::string sub_str;
	if (str.size() > 9)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void PhoneBook::display()
{
	std::cout << "===================Phone Book================\n";
	std::cout << "   Index   |FirstName | LastName | NickName |\n";
	std::cout << "---------------------------------------------\n";

	for(int i = 0; i < 8; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i << "|";
		print_substr(contact[i].get_first_name());
		std::cout << "|";
		print_substr(contact[i].get_last_name());
		std::cout << "|";
		print_substr(contact[i].get_nick_name());
		std::cout << "|" << std::endl;
	}
	std::string input;
	std::cout << "Enter the index of the entry to display : ";
	std::getline(std::cin, input);
	int input_num ;
	if (input.size() > 1 || input.size() == 0 || !isdigit(input[0]))
		return ;
	if (std::cin.eof())
		return ;
	input_num = atoi(input.c_str());
	if (input_num >= 0 && input_num < 8 && contact[input_num].get_first_name().size() > 0)
	{
		std::cout << "\n< Index {" << input_num << "} >\n";
		std::cout.width(contact[input_num].get_first_name().size() > 12 ? contact[input_num].get_first_name().size() + 1 : 13);
		std::cout << std::left << "|First Name";
		std::cout.width(contact[input_num].get_last_name().size() > 12 ? contact[input_num].get_last_name().size() + 1 : 13);
		std::cout<< "|Last Name";
		std::cout.width(contact[input_num].get_nick_name().size() > 12 ? contact[input_num].get_nick_name().size() + 1 : 13);
		std::cout<< "|Nick Name";
		std::cout.width(contact[input_num].get_phone_number().size() > 12 ? contact[input_num].get_phone_number().size() + 1: 13);
		std::cout<< "|Phone Number";
		std::cout.width(contact[input_num].get_secret().size() > 13 ? contact[input_num].get_secret().size() +1 : 13);
		std::cout<< "|Secret"<< "|" << std::endl;
		std::cout << std::right << "|" << std::setw(12) << contact[input_num].get_first_name();
		std::cout << "|" << std::setw(12) << contact[input_num].get_last_name();
		std::cout << "|" << std::setw(12) << contact[input_num].get_nick_name();
		std::cout << "|" << std::setw(12) << contact[input_num].get_phone_number();
		std::cout << "|" << std::setw(12) << contact[input_num].get_secret() << "|" << std::endl;
	}
}


void PhoneBook::phone_book()
{
	std::cout << "\nPhone Book\n";
    std::cout << "=============\n";

        std::cout << "ADD : Save new contact\n"; 
        std::cout << "SEARCH : Display contact\n";
        std::cout << "EXIT : The program quits\n";
    while (true)
    {
        std::string input;
		input = input_info( "\nEnter the command : ");
		if (strcmp(input.c_str(), "ADD") == 0)
			add_contact(); 
		else if (strcmp(input.c_str(), "SEARCH") == 0)
			display();
		else if (strcmp(input.c_str(), "EXIT") == 0)
		{
			std::cout << "The program quits\n";
			return ;
		}
	}
}