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

