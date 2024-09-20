#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{	
	brain = new Brain();
	this->brain->setIdea("I am a dog");
	std::cout << "Dog constructor called" << std::endl;	}

Dog::~Dog()
{	
	delete brain;
	std::cout << "Dog destructor called" << std::endl;	}

Dog::Dog(const Dog& a)
{	
	this->brain = new Brain(*a.brain);
	this->setType(a.getType());
	// std::cout << "Dog copy constructor called" << std::endl;
}
Dog & Dog::operator=(const Dog& a)
{
	if (this != &a)
	{
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*a.brain);
		this->setType(a.getType());
	}
	// std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}


void Dog::makeSound() const
{
	std::cout << "멍" << std::endl;
}

void Dog::setBrain(const Brain &brain)
{
	*this->brain = brain;
}

void Dog::displayBrain() const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->brain->getIdea(i) != "")
			std::cout << "brain" <<i <<" : " << this->brain->getIdea(i) << std::endl;

	}
}