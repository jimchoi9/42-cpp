#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name );

void checkLeaks()
{
	system("leaks Moar_brainz!");
}

int main()
{
	Zombie* zombies = zombieHorde( 10, "ZombieHorde" );

    for ( int i = 0; i < 10; ++i )
    {
		std::cout << "Zombie " << i + 1 << ": ";
        zombies[i].announce();
    }

    delete [] zombies;
	atexit(checkLeaks);
    return 0;
}