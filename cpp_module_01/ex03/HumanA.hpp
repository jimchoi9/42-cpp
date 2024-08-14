#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		bool attack();
	private:
		std::string name;
		Weapon &weapon;


};

#include "Weapon.hpp"

#endif