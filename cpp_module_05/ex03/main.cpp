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

	// std::cout << "\n========================{test 2}========================"<<std::endl;
		Bureaucrat tester2("tester2", 1);
		// AForm *form2 = new RobotomyRequestForm("form2"); // 72 45
	try {
		std::cout << *rrf << std::endl;
		tester2.signForm(*rrf);
		std::cout << *rrf << std::endl;
		tester2.executeForm(*rrf);
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	delete rrf;
	// std::cout << "\n========================{test 3}========================"<<std::endl;

	// 	Bureaucrat tester3("tester3", 25);
	// 	AForm *form3 = new PresidentialPardonForm("form3"); // 25 5
	// try {
	// 	std::cout << *form3 << std::endl;
	// 	tester3.signForm(*form3);
	// 	std::cout << *form3 << std::endl;
	// 	tester3.executeForm(*form3);
	// } catch(std::exception &e){
	// 	std::cout << e.what() << std::endl;
	// }

	// delete form3;

}