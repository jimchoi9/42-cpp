#pragma once
#include "Animal.hpp"

class Cat : public Animal {

	public:
		Cat();
		Cat(const Cat &c);
		Cat &operator = (const Cat &c);
		virtual ~Cat();
		virtual void makeSound() const;
};