#include "MutantStack.hpp"

#include <list>

int main( void ) {

	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	mstack.push(6);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << "=========================\n";
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "=========================\n";
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << std::endl;
    }
	std::cout << "=========================\n";

	std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    std::cout  << l.back() << std::endl; 
    l.pop_back();
    std::cout << l.back() << std::endl; 

    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
	std::cout << "=========================\n";

	for (std::list<int>::iterator  it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << std::endl;
    }
	std::cout << "=========================\n";
    for (std::list<int>::reverse_iterator  it = l.rbegin(); it != l.rend(); ++it) {
        std::cout << *it << std::endl; 
    }
	std::cout << "=========================\n";

	return 0;


}