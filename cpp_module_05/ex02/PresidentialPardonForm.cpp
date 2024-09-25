
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(name, 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &a) : AForm(a) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &a) {
	if (this != &a) {
		AForm::operator=(a);
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
		if (executor.getGrade() > getExecuteGrade()) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
    if (!getIsSigned()) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
        throw AForm::SignException();
    }
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}