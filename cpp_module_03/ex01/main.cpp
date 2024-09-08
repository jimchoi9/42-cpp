#include "ScavTrap.hpp"

int main()
{
	ScavTrap *scav = new ScavTrap("scav");
	ClapTrap *clapPtr = scav;
	ClapTrap *clap2 = new ClapTrap("clap");
	scav->attack("a");
	clapPtr->attack("a");
	clap2->attack("a");
	delete scav;
	delete clap2;
	return 0;
}
