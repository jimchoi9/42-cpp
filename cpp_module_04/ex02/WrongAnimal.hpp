#pragma once
#include <iostream>

class WrongAnimal {

	public:
		WrongAnimal();
		WrongAnimal(const std::string &name);
		WrongAnimal(const WrongAnimal &a);
		WrongAnimal &operator = (const WrongAnimal &a);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
		void setType(const std::string &type);
	protected:
		std::string type;
};