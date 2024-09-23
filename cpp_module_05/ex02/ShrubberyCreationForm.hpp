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
				const char *what() const _NOEXCEPT;
		};
		class SignException : public std::exception {
			public:
				const char *what() const _NOEXCEPT;
		};

	private:
		ShrubberyCreationForm();
};