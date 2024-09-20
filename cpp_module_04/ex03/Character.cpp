#include "Character.hpp"


class AMateria;
AMateria *Character::floor[10] = {0, };
int Character::fIdx = 0;

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
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character::Character(Character const &a) : name(a.name)
{
    for (int i = 0; i < 4; i++)
	{
		if (a.inventory[i])
			inventory[i] = a.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character & Character::operator=(Character const &a) 
{
    name = a.name;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i])
            delete inventory[i];
		if (a.inventory[i])
			inventory[i] = a.inventory[i]->clone();
		else
			inventory[i] = NULL;
    }
    return *this;
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
	delete m;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 ||!inventory[idx])
        return;
    floorHandler(inventory[idx]);
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    this->inventory[idx]->use(target);
}

void Character::floorHandler(AMateria *m)
{
    fIdx = fIdx % 10;
    if (floor[fIdx])
	{
        delete floor[fIdx];
	}
    floor[fIdx] = m;
    fIdx++;
}
void Character::displayFloor()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "["<< i << "] ";
        if (floor[i])
            std::cout <<floor[i]->getType() << std::endl;
        else
            std::cout << "NULL" << std::endl;
    }
}