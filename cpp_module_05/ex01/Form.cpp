#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade) {
	if (signGrade < 1 || executeGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || executeGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::~Form() {}

Form::Form(const Form &a) : name(a.name), isSigned(a.isSigned), signGrade(a.signGrade), executeGrade(a.executeGrade) {}

Form &Form::operator=(const Form &a) {
	if (this != &a) {
		isSigned = a.isSigned;
	}
	return *this;
}

void Form::beSigned(const Bureaucrat &a) {
	if (a.getGrade() > signGrade) {
		throw GradeTooLowException();
	}
	this->isSigned = true;
}

std::string Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getSignGrade() const {
	return signGrade;
}

int Form::getExecuteGrade() const {
	return executeGrade;
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << form.getName() << ", sign grade " << form.getSignGrade() 
	<<", execute grade " << form.getExecuteGrade() 
	<< ", is signed: " << form.getIsSigned() << ".";
	return os;
}

const char * Form::GradeTooHighException::what() const throw()   {
	return "Grade too high! ";
}
const char * Form::GradeTooLowException::what() const throw()   {
	return "Grade too low! ";
}