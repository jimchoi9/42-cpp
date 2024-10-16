#include "span.hpp"

int main( void ) {
	try {

	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	// sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "=================================\n";
	try {
	Span sp = Span(101);

	sp.addRange(0,100);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	} catch (std::out_of_range &e) {
		std::cout << e.what() << std::endl;
	}

return 0;	
}