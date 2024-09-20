#include "Brain.hpp"

Brain::Brain():idx(0)
{
	this->setIdea("Who am I?");
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{	std::cout << "Brain destructor called" << std::endl;	}

Brain::Brain(const Brain& a)
{
	for(int i=0; i < 100; i++)
		this->ideas[i] = a.ideas[i];
	this->idx = a.idx;
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain & Brain::operator=(const Brain& a)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &a)
	{
		for(int i=0; i < 100; i++)
			this->ideas[i] = a.ideas[i];
		this->idx = a.idx;
	}
	return *this;
}

void Brain::setIdea(const std::string &idea)
{

	idx = idx % 100;
	this->ideas[idx] = idea;
	idx++;
}

std::string Brain::getIdea(const int &idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cerr << "Brain: Cannot get idea, index out of bounds." << std::endl;
		return "";
	}
	return this->ideas[idx];
}
