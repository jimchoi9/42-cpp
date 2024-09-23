#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){

	std::cout << "========================{test 1}========================"<<std::endl;
	
		Bureaucrat jimchoi("jimchoi", 130);
		std::cout << jimchoi << std::endl;
		AForm *form1 = new ShrubberyCreationForm("form1");
	try {

		std::cout << *form1 << std::endl;
		// jimchoi.signForm(*form1);
		std::cout << *form1 << std::endl;

		jimchoi.executeForm(*form1);

	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
		delete form1;

	std::cout << "\n========================{test 2}========================"<<std::endl;

	std::cout << "\n========================{test 3}========================"<<std::endl;


}