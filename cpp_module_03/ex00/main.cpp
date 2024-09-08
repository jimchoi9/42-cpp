#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("a");
	a.setAttackDamage(1);
	a.setEnergyPoints(1);
	a.setHitPoints(1);
	ClapTrap b("b");
	b.setAttackDamage(10);
	b.setEnergyPoints(10);
	b.setHitPoints(10);


	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(10);

	return (0);
}