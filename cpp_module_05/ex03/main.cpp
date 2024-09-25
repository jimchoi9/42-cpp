#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){

	std::cout << "========================{test 1}========================"<<std::endl;
	
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat tester1("tester1", 1);
		// AForm *form2 = new RobotomyRequestForm("form2"); // 72 45
	try {
		std::cout << *rrf << std::endl;
		tester1.signForm(*rrf);
		std::cout << *rrf << std::endl;
		tester1.executeForm(*rrf);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	delete rrf;
	std::cout << "\n========================{test 2}========================"<<std::endl;
    AForm* rrf2;

	try {
		rrf2 = someRandomIntern.makeForm("wrongForm", "Bender");
		Bureaucrat tester2("tester2", 1);
			std::cout << *rrf2 << std::endl;
		tester2.signForm(*rrf2);
			std::cout << *rrf2 << std::endl;
		tester2.executeForm(*rrf2);
		delete rrf2;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}


}