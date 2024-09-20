
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

// void checkLeaks()
// {
// 	system("leaks Materia");
// }


int main()
{
	// atexit(checkLeaks);

	std::cout << "==========={test 1}===========\n" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp); //장착
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n\n==========={test 2}===========\n" << std::endl;
	me->use(2, *bob); // 아무 일도 안 일어남
	me->use(3, *bob); // 아무 일도 안 일어남

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp); // 아무 일도 안 일어남
	tmp = src->createMateria("cure");
	me->equip(tmp); // 아무 일도 안 일어남

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(2147483647, *bob); // 아무 일도 안 일어남

	std::cout << "\n\n==========={test 3}===========\n" << std::endl;
	Character jimchoi = Character("jimchoi");
	jimchoi.equip(src->createMateria("ice"));
	Character test;

	test = jimchoi;
	test.equip(src->createMateria("cure"));
	jimchoi.use(1, test);

	std::cout << "\n\n==========={test 4}===========\n" << std::endl;

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->unequip(0);
	me->unequip(1);

	Character::displayFloor();

	std::cout << "\n\n==========={test 5}===========\n" << std::endl;
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	Character::displayFloor();

	delete bob;
	delete me;
	delete src;
	return 0;
}