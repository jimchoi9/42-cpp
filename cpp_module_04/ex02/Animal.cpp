#include "Animal.hpp"

Animal::Animal() : type("default")
{	std::cout << "Animal constructor called" << std::endl;	}
Animal::Animal(const std::string &type) : type(type)
{	std::cout << "Animal constructor called" << std::endl;	}
Animal::~Animal()
{	std::cout << "Animal destructor called" << std::endl;	}
Animal::Animal(const Animal &a) : type(a.type)
{	std::cout << "Animal copy constructor called" << std::endl;	}
Animal &Animal::operator=(const Animal &a)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &a)
	{
		this->type = a.type;
	}
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes a generic sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}