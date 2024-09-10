#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const WrongCat &c);
		WrongCat &operator = (const WrongCat &c);
		virtual ~WrongCat();
		void makeSound() const;
};