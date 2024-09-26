
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"



Base * generate(void) {

	std::srand(std::time(0));
	int random = std::rand() % 3;
	if (random == 0) {
		return new A();
	} else if (random == 1) {
		return new B();
	} else {
		return new C();
	}
}


void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	}
}
void identify(Base& p) {
	
	try {
		Base &b = dynamic_cast<A&>(p);
		(void)b;
			std::cout << "A" << std::endl;
			return;
	} catch(std::exception &e) {
		(void)e;
	}
	try {
		Base &b = dynamic_cast<B&>(p);
		(void)b;
			std::cout << "B" << std::endl;
			return;
	} catch(std::exception &e) {
		(void)e;
	}
	try {
		Base &b = dynamic_cast<C&>(p);
		(void)b;
			std::cout << "C" << std::endl;
			return;
	} catch(std::exception &e) {
		(void)e;
	}
}

int main () {


	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return 0;
}