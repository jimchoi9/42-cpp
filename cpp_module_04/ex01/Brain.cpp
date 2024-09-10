#include "Brain.hpp"

Brain::Brain():size(0)
{	std::cout << "Brain constructor called" << std::endl;	}

Brain::~Brain()
{	
	std::cout << "Brain destructor called" << std::endl;	}

Brain::Brain(const Brain& a)
{
	for(int i=0; i < a.getSize(); i++)
		this->ideas[i] = a.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain & Brain::operator=(const Brain& a)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &a)
	{
		for(int i=0; i < a.getSize(); i++)
			this->ideas[i] = a.ideas[i];
	}
	return *this;
}

int Brain::getSize() const
{
	return size;
}
void Brain::setSize(const int &num)
{
	size += num;
}