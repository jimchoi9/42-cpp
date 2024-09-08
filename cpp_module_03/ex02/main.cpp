#include "FragTrap.hpp"

int main()
{
	FragTrap *Frag = new FragTrap("Frag");
	// ClapTrap *clapPtr = Frag;
	ClapTrap *clap2 = new ClapTrap("clap");
	Frag->highFivesGuys();
	// clapPtr->attack("a");
	clap2->attack("a");
	delete Frag;
	delete clap2;
	return 0;
}
