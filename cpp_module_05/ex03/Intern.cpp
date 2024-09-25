#include "Intern.hpp"



Intern::Intern(){}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &b) {
	(void)b;
	return *this;
}

Intern::Intern(const Intern &b){
	*this = b;
}

AForm * Intern::makeForm(const std::string &name, const std::string &target) const
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm * (Intern::*f[3])(const std::string &name) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	int form = -1;
		for(int i = 0; i < 3; i++)
		{
			if (name == names[i])
				form = i;
		}
		if (form == -1)
			throw TargetException();

		std::cout << "Intern creates " << target << std::endl;
		return (this->*f[form])(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}	


AForm *Intern::makePresidentialPardonForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

const char * Intern::TargetException::what() const throw()   {
	return "target doesn't exist";
}