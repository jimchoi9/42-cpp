#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, 72, 45)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &a) : AForm(a) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &a) {
	if (this != &a) {
		AForm::operator=(a);
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {

	if (executor.getGrade() > getExecuteGrade()) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
    if (!getIsSigned()) {
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because ";
        throw AForm::SignException();
    }

	std::cout << "Drilling sound... Bzzzzz..." << std::endl;
	std::srand(std::time(0)); // ㅅㅣ드를 현재 시간으로 설정
    if (rand() % 2) {
		std::cout << getName() << ", successfully robotomized!" << std::endl;
	} else {
		std::cout  << getName() << ", robotomy failed." << std::endl;
	}
}