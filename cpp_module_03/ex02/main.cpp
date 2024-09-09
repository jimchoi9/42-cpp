#include "FragTrap.hpp"

int main()
{
	FragTrap *Frag = new FragTrap("Frag");
	ClapTrap *clapPtr = Frag;
std::cout << "Frag : " << Frag->getName() << std::endl;
std::cout << "clapPtr : " << clapPtr->getName() << std::endl;

	Frag->highFivesGuys();
	clapPtr->attack("a");
	delete Frag;

	return 0;
}
