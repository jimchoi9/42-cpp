#include "Bureaucrat.hpp"

int main(){

	std::cout << "========================{test 1}========================"<<std::endl;
	
	try {
		Bureaucrat temp1("jimchoi", 151);
		std::cout << temp1 << std::endl;
		temp1.incrementGrade();
		std::cout << "throw test 1" << std::endl;

	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================{test 1}========================"<<std::endl;
	
	try {
		Bureaucrat temp1("jimchoi", 151);
		std::cout << temp1 << std::endl;
		temp1.incrementGrade();
		std::cout << "throw test 1" << std::endl;

	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "========================{test 2}========================"<<std::endl;
	
	try {
		Bureaucrat temp1("jimchoi", 1);
		std::cout << temp1 << std::endl;
		temp1.decrementGrade();
		std::cout << temp1 << std::endl;
		temp1.incrementGrade();
		std::cout << temp1 << std::endl;
		temp1.incrementGrade();
		std::cout << temp1 << std::endl;
		std::cout << "throw test 2" << std::endl;

	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}