#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice();
		~Ice();
		Ice(const Ice& a);
		Ice& operator=(const Ice& a);
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;

};