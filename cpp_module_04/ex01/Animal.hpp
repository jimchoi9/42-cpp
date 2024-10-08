#pragma once
#include <iostream>

class Animal {

	public:
		Animal();
		Animal(const std::string &name);
		Animal(const Animal &a);
		Animal &operator = (const Animal &a);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
		void setType(const std::string &type);
	protected:
		std::string type;
};