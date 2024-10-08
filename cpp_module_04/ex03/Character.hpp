#include "ICharacter.hpp"


class Character : public ICharacter {
	public:
		Character();
		Character(const std::string &name);
		Character(Character const &a);
		Character & operator=(Character const &a);
		~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		static void displayFloor();
	private:
		std::string name;
		AMateria* inventory[4];
		static AMateria *floor[10];
		static void floorHandler(AMateria *m);
		static int fIdx;
};
