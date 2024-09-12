#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{	
	brain = new Brain();
	this->brain->setIdea("I am a WrongCat");
	std::cout << "WrongCat constructor called" << std::endl;	}

WrongCat::~WrongCat()
{	
	delete brain;
	std::cout << "WrongCat destructor called" << std::endl;	}

WrongCat::WrongCat(const WrongCat& a)
{	
	this->brain = a.brain;
	this->setType(a.getType());
	// std::cout << "WrongCat copy constructor called" << std::endl;
}
WrongCat & WrongCat::operator=(const WrongCat& a)
{
	if (this != &a)
	{
		if (this->brain)
			delete this->brain;
		this->brain = a.brain;
		this->setType(a.getType());
	}
	// std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}


void WrongCat::makeSound() const
{
	std::cout << "안녕하세요." << std::endl;
}

void WrongCat::setBrain(const Brain &brain)
{
	*this->brain = brain;
}

void WrongCat::displayBrain() const
{
	for (int i = 0; i < this->brain->getSize(); i++)
		std::cout << "brain" <<i <<" : " << this->brain->getIdea(i) << std::endl;
}