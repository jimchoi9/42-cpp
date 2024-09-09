#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{	std::cout << "ClapTrap constructor called" << std::endl;	}
ClapTrap::ClapTrap(const std::string &name)
: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{	std::cout << "ClapTrap constructor called" << std::endl;	}

ClapTrap::ClapTrap(const ClapTrap &a) : name(a.name), hitPoints(a.hitPoints), energyPoints(a.energyPoints), attackDamage(a.attackDamage)
{	std::cout << "ClapTrap copy constructor called" << std::endl;	}

ClapTrap &ClapTrap::operator=(const ClapTrap &a)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	if (this != &a)
	{
		this->name = a.name;
		this->hitPoints = a.hitPoints;
		this->energyPoints = a.energyPoints;
		this->attackDamage = a.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{	std::cout << "ClapTrap destructor called" << std::endl;	}

void ClapTrap::attack(std::string const & target)
{
	if (this->energyPoints < 1 || this->hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->name << " can't attacks " << target << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints -= 1;
	}
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints < 1 || this->hitPoints < 1)
	{
		std::cout << "ClapTrap " << this->name << " can't repaired :(" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints -= 1;
	}
}

int ClapTrap::getHitPoints() const
{	return this->hitPoints;	}

int ClapTrap::getEnergyPoints() const
{	return this->energyPoints;	}

int ClapTrap::getAttackDamage() const
{	return this->attackDamage;	}

std::string ClapTrap::getName() const
{	return this->name;	}

void ClapTrap::setName(const std::string& name)
{	this->name = name;	}

void ClapTrap::setHitPoints(const int& hitPoints)
{	this->hitPoints = hitPoints;	}

void ClapTrap::setEnergyPoints(const int& energyPoints)
{	this->energyPoints = energyPoints;	}

void ClapTrap::setAttackDamage(const int &attackDamage)
{	this->attackDamage = attackDamage;	}

