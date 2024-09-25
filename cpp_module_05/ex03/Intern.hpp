#pragma once
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern {

	public:
		Intern();
		~Intern();
		Intern(Intern const &a);
		Intern &operator=(Intern const &a);
		AForm *makeForm(const std::string &name, const std::string &target) const;

		AForm *makeShrubberyCreationForm(const std::string &name) const;
		AForm *makeRobotomyRequestForm(const std::string &name) const;
		AForm *makePresidentialPardonForm(const std::string &name) const;
		
		class TargetException : public std::exception {
			public:
				const char *what() const ;
		};
	private:
		

};