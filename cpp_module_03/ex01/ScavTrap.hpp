#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &a);
		ScavTrap &operator=(const ScavTrap &a);
		virtual ~ScavTrap();

		virtual void attack(std::string const & target);
		void guardGate();
	private:
		ScavTrap();
};