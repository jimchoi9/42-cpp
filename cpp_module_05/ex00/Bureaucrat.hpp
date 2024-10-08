#pragma once
#include <iostream>
#include <exception>



class Bureaucrat {

	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() ; 
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

	private:
		Bureaucrat();
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);