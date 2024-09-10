#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{	std::cout << "WrongCat constructor called" << std::endl;	}

WrongCat::~WrongCat()
{	std::cout << "WrongCat destructor called" << std::endl;	}

WrongCat::WrongCat(const WrongCat& a)
{	
	this->setType(a.getType());
	std::cout << "WrongCat copy constructor called" << std::endl;	}
WrongCat & WrongCat::operator=(const WrongCat& a)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &a)
		this->setType(a.getType());
	return *this;
}


void WrongCat::makeSound() const
{
	std::cout << "괙" << std::endl;
}