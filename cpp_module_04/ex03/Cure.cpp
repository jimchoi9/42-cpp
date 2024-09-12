#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{	}

Cure::~Cure()
{	}

Cure::Cure(const Cure& a) :AMateria(a)
{	}

Cure &Cure::operator=(const Cure &a)
{
	if (this != &a)
		this->type = a.type;
	return *this;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}