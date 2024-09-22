#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
	if (this != &b) {
		grade = b.grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade == 1) {
		throw GradeTooHighException();
	}
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade == 150) {
		throw GradeTooLowException();
	}
	grade++;
}


void Bureaucrat::signForm(Form &form) {
	if (!form.getIsSigned()) {
		if (grade <= form.getSignGrade()) {
			std::cout << name << " signed " << form.getName() << std::endl;
			form.beSigned(*this);
		} else {
			std::cout << name << " couldn't sign " << form.getName() << " because ";
			throw Form::GradeTooLowException();
		}
	} else {
		std::cout << name << " cannot sign " << form.getName() << " is already signed." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() <<".";
	return os;
}

const char * Bureaucrat::GradeTooHighException::what() const _NOEXCEPT {
	return "Grade too high! ";
}
const char * Bureaucrat::GradeTooLowException::what() const _NOEXCEPT {
	return "Grade too low! ";
}