#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	public:
		ShrubberyCreationForm(const std::string name);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &a);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &a);

		virtual void execute(Bureaucrat const &executor) const;

		class FileOpenException : public std::exception {
			public:
				const char *what() const ;
		};


	private:
		ShrubberyCreationForm();
};