#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap("default")
{	
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{	
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &a)
{	
	this->name = a.name;
	this->hitPoints = a.hitPoints;
	this->energyPoints = a.energyPoints;
	this->attackDamage = a.attackDamage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
} 

ScavTrap &ScavTrap::operator = (const ScavTrap &a)
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &a)
	{
		this->name = a.name;
		this->hitPoints = a.hitPoints;
		this->energyPoints = a.energyPoints;
		this->attackDamage = a.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{	std::cout << "ScavTrap destructor called" << std::endl;	}

void ScavTrap::attack(std::string const & target)
{
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
	{
		std::cout << "ScavTrap " << this->getName() << " can't attacks " << target << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
}

void ScavTrap::guardGate()
{
	if (this->getEnergyPoints() < 1 || this->getHitPoints() < 1)
	{
		std::cout << "ScavTrap " << this->getName() << " can't guard the gate" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->getName() << " have enterred in Gate keeper mode" << std::endl;
}