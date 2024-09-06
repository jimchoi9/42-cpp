#pragma once
#include <iostream>

class ClapTrap{

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &a);
		ClapTrap &operator=(const ClapTrap &a);
		~ClapTrap();

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		std::string getName() const;
		
		void setHitPoints(const int &hitPoints);
		void setEnergyPoints(const int &energyPoints);
		void setAttackDamage(const int &attackDamage);

	private:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
		ClapTrap();
};