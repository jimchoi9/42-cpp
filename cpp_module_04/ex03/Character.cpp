#include "Character.hpp"


class AMateria;
AMateria *Character::floor[10] = {0, };
int Character::fIdx = 0;

Character::Character() : name("default") , size(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string& name) : name(name) , size(0)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

Character::Character(Character const &a) : name(a.name), size(a.size)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = a.inventory[i]->clone();
}

Character & Character::operator=(Character const &a) 
{
    name = a.name;
    size = a.size;
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

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            size ++;
            return;
        }
    }
    // std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 ||!inventory[idx])
        return;
    // TODO: 아이템 버리기
    floorHandler(inventory[idx]);
    inventory[idx] = NULL;
    // this->size --;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !inventory[idx])
        return;
    this->inventory[idx]->use(target);
    displayFloor();
}

void Character::floorHandler(AMateria *m)
{
    fIdx = fIdx % 10;
    if (floor[fIdx])
        delete floor[fIdx];
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