#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string &name);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &a);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &a);

		virtual void execute(Bureaucrat const &executor) const;
	private:
		PresidentialPardonForm();
};
