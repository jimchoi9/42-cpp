#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
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


	// WrongCat wrongCat1;
	// WrongCat wrongCat2 = wrongCat1;


	// std::cout << "WrongCat 1: " << std::endl;
	// wrongCat1.displayBrain();
	// std:Animal
	// Brain dogBrain;
	// dogBrain.setIdea("I am a dog");
    // wrongCat1.setBrain(dogBrain);

	
	// std::cout << "WrongCat 1: " << std::endl;
	// wrongCat1.displayBrain();
	// std::cout << "WrongCat 2: " << std::endl;
    // wrongCat2.displayBrain();

    // Animal animal;
	return 0;
}