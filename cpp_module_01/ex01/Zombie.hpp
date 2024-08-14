# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
	void setName(std::string name);
// Zombie* zombieHorde( int N, std::string name ) 이거 여기 있어도 되는지

private:
    std::string name;
};
#endif