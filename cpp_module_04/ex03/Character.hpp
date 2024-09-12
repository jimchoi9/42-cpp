#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character(std::string name);
		Character(Character const &a);
		Character & operator=(Character const &a);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	private:
		std::string name;
		AMateria* inventory[4];
};
