
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void checkLeaks()
{
	system("leaks Materia");
}


int main()
{
// atexit(checkLeaks);
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
// AMateria* tmp;
// tmp = src->createMateria("cure");
// std::cout << tmp->getType() << std::endl;
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp); //장착
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
me->unequip(0);
me->unequip(1);
me->unequip(2);
me->unequip(3);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
me->unequip(0);
me->unequip(1);
me->unequip(2);
me->unequip(3);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
me->unequip(0);
me->unequip(1);
me->unequip(2);
me->unequip(3);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("ice");
me->equip(tmp);
me->unequip(0);
me->unequip(1);
me->unequip(2);
me->unequip(3);



ICharacter* bob = new Character("bob");
tmp = src->createMateria("ice");
me->equip(tmp);
me->use(0, *bob);
me->unequip(0);
tmp = src->createMateria("ice");
me->equip(tmp);
// tmp = src->createMateria("ice");
// bob->equip(tmp);
// bob->unequip(0);
std::cout << "======================" << std::endl;
me->use(1, *bob);

// me->use(0, *bob);
// me->use(1, *bob);
// me->use(2, *bob);
// me->use(3, *bob);
// me->use(4, *bob);
delete bob;
delete me;
delete src;
return 0;
}