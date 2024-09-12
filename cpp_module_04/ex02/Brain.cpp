#include "Brain.hpp"

Brain::Brain():size(0)
{
	for(int i=0; i < 100; i++)
		this->ideas[i] = "\0";
	this->setIdea("Who am I?");
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{	std::cout << "Brain destructor called" << std::endl;	}

Brain::Brain(const Brain& a)
{
	for(int i=0; i < 100; i++)
		this->ideas[i] = a.ideas[i];
	this->size = a.size;
	std::cout << "Brain copy constructor called" << std::endl;
}
Brain & Brain::operator=(const Brain& a)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &a)
	{
		for(int i=0; i < 100; i++)
			this->ideas[i] = a.ideas[i];
		this->size = a.size;
	}
	return *this;
}

void Brain::setIdea(const std::string &idea)
{

	size = size % 100;
	this->ideas[size] = idea;
	size++;
}

std::string Brain::getIdea(const int &idx) const
{
	if (idx < 0 || idx >= size)
	{
		std::cerr << "Brain: Cannot get idea, index out of bounds." << std::endl;
		return "\0";
	}
	return this->ideas[idx];
}

int Brain::getSize() const
{
	return size;
}