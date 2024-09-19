#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure();
		~Cure();
		Cure(const Cure& a);
		Cure& operator=(const Cure& a);
		virtual void use(ICharacter& target);
		virtual AMateria* clone() const;

};