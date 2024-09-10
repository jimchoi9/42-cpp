#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

	public:
		Dog();
		Dog(const Dog &c);
		Dog &operator = (const Dog &c);
		virtual ~Dog();
		virtual void makeSound() const;
	private:
        Brain *brain;
};