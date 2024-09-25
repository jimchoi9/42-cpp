#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw GradeTooLowException();
	}
}

AForm::~AForm() {}

AForm::AForm(const AForm &a) : name(a.name), isSigned(a.isSigned), signGrade(a.signGrade), executeGrade(a.executeGrade) {}

AForm &AForm::operator=(const AForm &a) {
	if (this != &a) {
		isSigned = a.isSigned;
	}
	return *this;
}

void AForm::beSigned(const Bureaucrat &a) {
	if (a.getGrade() > signGrade) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getSignGrade() const {
	return signGrade;
}

int AForm::getExecuteGrade() const {
	return executeGrade;
}


std::ostream &operator<<(std::ostream &os, const AForm &form) {
	
	os << form.getName() << ", sign grade " << form.getSignGrade() 
	<<", execute grade " << form.getExecuteGrade() 
	<< ", is signed: " << form.getIsSigned() << ".";
	return os;
}

const char * AForm::GradeTooHighException::what() const throw()   {
	return "Grade too high! ";
}
const char * AForm::GradeTooLowException::what() const throw()   {
	return "Grade too low! ";
}

const char * AForm::SignException::what() const throw()   {
	return "unsigned form";
}