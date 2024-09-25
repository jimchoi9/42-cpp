#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a) : AForm(a) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
	if (this != &a) {
		AForm::operator=(a);
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > getExecuteGrade()) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
    if (!getIsSigned()) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
        throw AForm::SignException();
    }
	std::ofstream file(getName()+"_shrubbery");
	if (file.fail()) {
		throw FileOpenException();
	}
	file << "           ccee88oo        "<< std::endl;
	file << "      C8O8O8Q8PoOb o8oo    "<< std::endl;
	file << "   dOB69QO8PdUOpugoO9bD    "<< std::endl;
	file << " CgggbU8OU qOp qOdoUOdcb   "<< std::endl;
	file << "     6OuU  /p u gcoUodpP   "<< std::endl;
	file << "        \\\\\\//  /douUP      "<< std::endl;
	file << "          \\\\\\////          "<< std::endl;
	file << "           |||/\\           "<< std::endl;
	file << "           |||\\/           "<< std::endl;
	file << "           |||||     \\O/   "<< std::endl;
	file << "           |||||      |    "<< std::endl;
	file << "     .....//||||\\...  /\\   " << std::endl;

	file << std::endl;
	file.close();
}


const char * ShrubberyCreationForm::FileOpenException::what() const throw()   {
	return "file open error";
}
