#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &b);
		Bureaucrat &operator=(Bureaucrat const &b);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const ;
		};

	private:
		Bureaucrat();
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);