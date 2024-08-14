#include "HumanB.hpp"

HumanB::HumanB(std::string name) :name(name)
{
}
HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon newWeapon)
{
	this->weapon = &newWeapon;
}

bool HumanB::attack()
{
	std::string tmp = weapon->getType();

	if(tmp.empty())
	{
		std::cout << name << " has no weapons." << std::endl;
		return false;
	}
	else
	{
		std::cout << name << " attacks with their" << tmp << std::endl;
		return true;
	}

}