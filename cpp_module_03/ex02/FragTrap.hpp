#pragma once
#include "ClapTrap.hpp"

class FragTrap : protected ClapTrap
{
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &a);
		FragTrap &operator=(const FragTrap &a);
		virtual ~FragTrap();

		void highFivesGuys();
	private:
		FragTrap();
};