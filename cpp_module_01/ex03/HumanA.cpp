#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :name(name), weapon(weapon)
{}
HumanA::~HumanA()
{}

bool HumanA::attack()
{
		std::cout << name << " attacks with their" << weapon.getType() << std::endl;
		return true;
}