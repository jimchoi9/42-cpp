#pragma once
#include <iostream>
#include <exception>
#include <string>




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

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const _NOEXCEPT;
		};

	private:
		Bureaucrat();
		const std::string name;
		int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);