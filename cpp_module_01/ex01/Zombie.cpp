#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}
Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << name << " : " << "I'm dying" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}
