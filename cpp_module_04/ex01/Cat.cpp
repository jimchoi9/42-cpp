#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{	std::cout << "Cat constructor called" << std::endl;	}

Cat::~Cat()
{	
	delete brain;
	std::cout << "Cat destructor called" << std::endl;	}

Cat::Cat(const Cat& a)
{	
	this->setType(a.getType());
	std::cout << "Cat copy constructor called" << std::endl;	}
Cat & Cat::operator=(const Cat& a)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &a)
		this->setType(a.getType());
	return *this;
}


void Cat::makeSound() const
{
	std::cout << "괙" << std::endl;
}