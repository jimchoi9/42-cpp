#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{	}

Ice::~Ice()
{	}

Ice::Ice(const Ice& a) :AMateria(a)
{	}

Ice &Ice::operator=(const Ice &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}