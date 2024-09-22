#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){

	std::cout << "========================{test 1}========================"<<std::endl;
	
	try {
		Bureaucrat temp1("jimchoi", 6);
		std::cout << temp1 << std::endl;
		Form form1("form1", 5, 5);
		std::cout << form1 << std::endl;
		
		temp1.signForm(form1);
		std::cout << form1 << std::endl;

	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n========================{test 2}========================"<<std::endl;
	
	try {
		Bureaucrat temp1("jimchoi", 6);
		std::cout << temp1 << std::endl;
		temp1.incrementGrade();
		std::cout << temp1 << std::endl;
		Form form1("form1", 5, 5);
		std::cout << form1 << std::endl;
		
		temp1.signForm(form1);

		std::cout << form1 << std::endl;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n========================{test 3}========================"<<std::endl;

	try {
		Form form1("form1", 0, 5);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form form1("form1", 5, 0);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form form1("form1", 151, 5);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		Form form1("form1", 5, 151);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

}