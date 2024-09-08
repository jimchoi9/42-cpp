#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << "FragTrap constructor called" << std::endl;	
}

FragTrap::FragTrap(const FragTrap &a)
: ClapTrap(a)
{	std::cout << "FragTrap copy constructor called" << std::endl;	} 

FragTrap &FragTrap::operator = (const FragTrap &a)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &a)
	{
		ClapTrap::operator=(a);
	}
	return *this;
}

FragTrap::~FragTrap()
{	std::cout << "FragTrap destructor called" << std::endl;	}



void FragTrap::highFivesGuys()
{
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
	{
		std::cout << "FragTrap " << this->getName() << " can't high five" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->getName() << "gives a high five to everyone!" << std::endl;
}