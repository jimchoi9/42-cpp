#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
		Form(const std::string name, int signGrade, int executeGrade);
		~Form();
		Form(const Form &a);
		Form &operator=(const Form &a);
		void beSigned(const Bureaucrat &a);

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const ;
		};
	private:
		Form();
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);