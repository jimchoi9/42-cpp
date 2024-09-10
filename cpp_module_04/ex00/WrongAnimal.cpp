#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default")
{	std::cout << "WrongAnimal constructor called" << std::endl;	}
WrongAnimal::WrongAnimal(const std::string &type) : type(type)
{	std::cout << "WrongAnimal constructor called" << std::endl;	}
WrongAnimal::~WrongAnimal()
{	std::cout << "WrongAnimal destructor called" << std::endl;	}
WrongAnimal::WrongAnimal(const WrongAnimal &a) : type(a.type)
{	std::cout << "WrongAnimal copy constructor called" << std::endl;	}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &a)
	{
		this->type = a.type;
	}
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a generic sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}