#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){

	std::cout << "========================{test 1}========================"<<std::endl;
	
		Bureaucrat tester1("tester1", 145);
		std::cout << tester1 << std::endl;
		AForm *form1 = new ShrubberyCreationForm("form1"); // 145 137
	
	try {
		std::cout << *form1 << std::endl;
		tester1.signForm(*form1);
		std::cout << *form1 << std::endl;
		tester1.executeForm(*form1);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	delete form1;

	std::cout << "\n========================{test 2}========================"<<std::endl;
		Bureaucrat tester2("tester2", 72);
		AForm *form2 = new RobotomyRequestForm("form2"); // 72 45
	try {
		std::cout << *form2 << std::endl;
		tester2.signForm(*form2);
		std::cout << *form2 << std::endl;
		tester2.executeForm(*form2);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	delete form2;
	std::cout << "\n========================{test 3}========================"<<std::endl;

		Bureaucrat tester3("tester3", 25);
		AForm *form3 = new PresidentialPardonForm("form3"); // 25 5
	try {
		std::cout << *form3 << std::endl;
		tester3.signForm(*form3);
		std::cout << *form3 << std::endl;
		tester3.executeForm(*form3);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	delete form3;

}