#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{	}

AMateria::AMateria(std::string const &type) : type(type)
{	}

AMateria::~AMateria()
{	}

AMateria ::AMateria(const AMateria &a) : type(a.type)
{}

AMateria &AMateria::operator=(const AMateria &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}


void AMateria::use(ICharacter &target)
{
	std::cout << "Use " << std::endl;
}
