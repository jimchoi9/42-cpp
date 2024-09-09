#pragma once
#include <iostream>

class ClapTrap{

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &a);
		ClapTrap &operator=(const ClapTrap &a);
		virtual ~ClapTrap();

		virtual void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		
		void setName(const std::string &name);
		void setHitPoints(const int &hitPoints);
		void setEnergyPoints(const int &energyPoints);
		void setAttackDamage(const int &attackDamage);

	protected:
		std::string name;
		int hitPoints;
		int energyPoints;
		int attackDamage;
};