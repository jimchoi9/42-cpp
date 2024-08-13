# ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon 
{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		const std::string &getType();
};

#include <iostream>

#endif