#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{	
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;	}

Dog::~Dog()
{	
	delete brain;
	std::cout << "Dog destructor called" << std::endl;	}

Dog::Dog(const Dog& a)
{	
	this->setType(a.getType());
	this->brain = new Brain(*a.brain);
	std::cout << "Dog copy constructor called" << std::endl;	}
Dog & Dog::operator=(const Dog& a)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &a)
	{
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*a.brain);
		this->setType(a.getType());
	}
	return *this;
}


void Dog::makeSound() const
{
	std::cout << "멍" << std::endl;
}