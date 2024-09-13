#include "Character.hpp"

Character::Character() : name("default") 
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string& name) : name(name) 
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

Character::Character(Character const &a) 
{
    name = a.name;
    for (int i = 0; i < 4; i++)
        inventory[i] = a.inventory[i]->clone();
}

Character & Character::operator=(Character const &a) 
{
    name = a.name;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
        inventory[i] = a.inventory[i]->clone();
    }
    return *this;
}

std::string const & Character::getName() const
{
    return name;
}

