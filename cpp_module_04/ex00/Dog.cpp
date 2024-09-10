#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{	std::cout << "Dog constructor called" << std::endl;	}

Dog::~Dog()
{	std::cout << "Dog destructor called" << std::endl;	}

Dog::Dog(const Dog& a)
{	
	this->setType(a.getType());
	std::cout << "Dog copy constructor called" << std::endl;	}
Dog & Dog::operator=(const Dog& a)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &a)
		this->setType(a.getType());
	return *this;
}


void Dog::makeSound() const
{
	std::cout << "멍" << std::endl;
}