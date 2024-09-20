#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


// void check_leaks(){
// 	system("leaks Animal");
// }

int main()
{
	// atexit(check_leaks);
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "======================================================================" << std::endl;

	Dog Dog1;
	Dog Dog2 = Dog1;

	Brain catBrain;
	catBrain.setIdea("I am a cat");
	std::cout << "Dog 1: " << std::endl;
	Dog1.displayBrain();
	std::cout << "Dog 2: " << std::endl;
	Dog2.displayBrain();

	Dog1.setBrain(catBrain);

	std::cout << "Dog 1: " << std::endl;
	Dog1.displayBrain();
	std::cout << "Dog 2: " << std::endl;
	Dog2.displayBrain();


	// Animal animal;

	return 0;
}