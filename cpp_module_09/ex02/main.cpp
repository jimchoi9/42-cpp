#include "PmergeMe.hpp"


int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: invalid number of arguments" << std::endl;
		return 1;
	}
	std::string str = av[1];
	Pmergeme p(str);
	return 0;
}