#pragma once
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &c);
		WrongCat &operator = (const WrongCat &c);
		virtual ~WrongCat();
		void makeSound() const;

		void setBrain(const Brain &brain);
		void displayBrain() const;
	private:
	    Brain *brain;
};