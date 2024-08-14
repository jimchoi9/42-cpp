#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		bool attack();
		void setWeapon(Weapon newWeapon);
	private:
		std::string name;
		Weapon *weapon;


};

#include "Weapon.hpp"

#endif