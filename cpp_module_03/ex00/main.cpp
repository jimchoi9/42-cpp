#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("a");
	ClapTrap b("b");


	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
	b.beRepaired(10);

	return (0);
}