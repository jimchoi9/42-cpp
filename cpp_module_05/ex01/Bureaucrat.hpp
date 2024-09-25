#pragma once
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {

	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat &operator=(Bureaucrat const &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw()  ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw()  ;
		};

	private:
		Bureaucrat();
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);