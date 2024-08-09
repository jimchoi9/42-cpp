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

	// std::cout << "Enter first name : ";
    // contact[index].set_first_name(input_info());
	// std::cout << "Enter last name : ";
    // contact[index].set_last_name(input_info());
	// std::cout << "Enter nick name : ";
    // contact[index].set_nick_name(input_info());
std::cout << "idx : " << index << std::endl;
	while(true)
	{
		std::cout << "Enter phone number : ";
		if (contact[index].set_phone_number(input_info()))
			break;
	}
	// std::cout << "Enter secret : ";
    // contact[index].set_secret(input_info());
	index ++;
	return (true);
}

void PhoneBook::display(int index)
{
	if (index >= 0 && index < 8 && contact[index].get_first_name().size() > 0)
	{
		std::cout << "============Index {" << index << "}===============\n";
		std::cout << " Index | FirstName | LastName | NickName | PhoneNum |  Secret  |\n";
		std::cout << std::setw(contact[index].get_first_name().size() + 2);
		std::cout <<"| " << contact[index].get_first_name();
        std::cout << std::setw(contact[index].get_last_name().size() + 2);
        std::cout << "| " << contact[index].get_last_name();
        std::cout << std::setw(contact[index].get_nick_name().size() + 2);
        std::cout << "| " << contact[index].get_nick_name();
		std::cout << std::setw(contact[index].get_phone_number().size() + 2);
        std::cout << "| " << contact[index].get_phone_number();
        std::cout << std::setw(contact[index].get_secret().size() + 2);
        std::cout << "| " << contact[index].get_secret();
		std::cout << "---------------------------------------------\n";
	}
	else
	{
		std::cout << "===================Phone Book================\n";
		std::cout << "   Index   |FirstName | LastName | NickName |\n";
		std::cout << "---------------------------------------------\n";
		std::cout << "-0123456789-0123456789-0123456789-0123456789-\n";
		for(int i = 0; i < 8; i++)
		{
			std::cout << std::setw(10);

		}
	}
	
}


void PhoneBook::phone_book()
{
	std::cout << "\nPhone Book\n";
    std::cout << "=============\n";

        std::cout << "ADD : Save new contact\n"; 
        std::cout << "SEARCH : Display a specific contact\n";
        std::cout << "EXIT : The program quits\n";
    while (true)
    {

        std::string input;
        std::cout << "\nChoose an option : ";
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
			// std::cout << "ADD : Save new contact\n"; 
				break;
			case 2:
				// search_by_first_name();
			std::cout << "SEARCH : Display a specific contact\n";
				break;
			case 3:
				// display_all_users();
			std::cout << "EXIT : The program quits\n";
				return ;
			default:
			std::cout << "======================\n";
			std::cout << "ADD : Save new contact\n"; 
			std::cout << "SEARCH : Display a specific contact\n";
			std::cout << "EXIT : The program quits\n";
			std::cout << "======================\n";
				break;
		}
		std::cin.clear();
		clearerr(stdin);
	}
}