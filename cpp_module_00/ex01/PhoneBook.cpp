#include "PhoneBook.hpp"

std::string PhoneBook::input_info()
{
	std::string str;
	while (str.empty())
	{
		std::getline(std::cin, str);
		if (std::cin.fail())
		{
            std::cin.clear();
            clearerr(stdin);
			continue;
        }
	}
	return (str);
}

bool PhoneBook::add_contact()
{
	std::string number;
	index = index % 8;

	std::cout << "Enter first name : ";
    contact[index].set_first_name(input_info());
	std::cout << "Enter last name : ";
    contact[index].set_last_name(input_info());
	std::cout << "Enter nick name : ";
    contact[index].set_nick_name(input_info());
std::cout << "idx : " << index << std::endl;
	while(true)
	{
		std::cout << "Enter phone number : ";
		if (contact[index].set_phone_number(input_info()))
			break;
	}
	std::cout << "Enter secret : ";
    contact[index].set_secret(input_info());
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
        std::cout << "\nEnter the command : ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;

		int choice;
		if (strcmp(input.c_str(), "ADD") == 0)
			choice = 1;
		else if (strcmp(input.c_str(), "SEARCH") == 0)
			choice = 2;
		else if (strcmp(input.c_str(), "EXIT") == 0)
			choice = 3;
		else
			choice = 0;

        switch (choice)
        {
			case 1:
				add_contact(); 
				break;
			case 2:
				display();
				break;
			case 3:
			std::cout << "The program quits\n";
				return ;
			default:
			std::cout << "========================\n";
			std::cout << "ADD : Save new contact\n"; 
			std::cout << "SEARCH : Display contact\n";
			std::cout << "EXIT : The program quits\n";
			std::cout << "========================\n";
				break;
		}
		std::cin.clear();
		clearerr(stdin);
	}
}