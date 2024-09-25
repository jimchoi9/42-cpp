#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public:
		AForm(const std::string name, int signGrade, int executeGrade);
		virtual ~AForm();
		AForm(const AForm &a);
		AForm &operator=(const AForm &a);
		void beSigned(const Bureaucrat &a);

		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw()  ;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw()  ;
		};
		class SignException : public std::exception {
			public:
				const char *what() const throw()  ;
		};
	private:
		AForm();
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int executeGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);