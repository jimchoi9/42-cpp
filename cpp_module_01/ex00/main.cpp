#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump( std::string name );

int main() {
	Zombie zombie("Stack");
	Zombie *zombie1 = newZombie("Heap");
	randomChump("Random");
	zombie.announce();
	zombie1->announce();

	delete zombie1;
	return 0;
}