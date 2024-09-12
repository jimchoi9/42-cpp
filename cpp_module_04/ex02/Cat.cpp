#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{	
	brain = new Brain();
	this->brain->setIdea("I am a Cat");
	std::cout << "Cat constructor called" << std::endl;	}

Cat::~Cat()
{	
	delete brain;
	std::cout << "Cat destructor called" << std::endl;	}

Cat::Cat(const Cat& a)
{	
	this->brain = new Brain(*a.brain);
	this->setType(a.getType());
	// std::cout << "Cat copy constructor called" << std::endl;
}
Cat & Cat::operator=(const Cat& a)
{
	if (this != &a)
	{
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*a.brain);
		this->setType(a.getType());
	}
	// std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}


void Cat::makeSound() const
{
	std::cout << "괙" << std::endl;
}

void Cat::setBrain(const Brain &brain)
{
	*this->brain = brain;
}

void Cat::displayBrain() const
{
	for (int i = 0; i < this->brain->getSize(); i++)
		std::cout << "brain" <<i <<" : " << this->brain->getIdea(i) << std::endl;
}