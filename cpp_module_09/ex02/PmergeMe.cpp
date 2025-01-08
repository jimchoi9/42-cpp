#include "PmergeMe.hpp"

Pmergeme::Pmergeme() {}

Pmergeme::Pmergeme(const Pmergeme &other) {
	*this = other;
}

Pmergeme::~Pmergeme() {}

Pmergeme &Pmergeme::operator=(const Pmergeme &other) {
	(void)other;
	return *this;
}

Pmergeme::Pmergeme(std::string &str) {
	readInput(str);
	printResult();
	vStartTime = time(NULL);
	lStartTime = time(NULL);
	
}

void Pmergeme::readInput(std::string &str) {
	std::string tmp;
	std::stringstream ss(str);

	while (ss >> tmp) {
		if (isdigit(tmp[0])) {
			vData.push_back(atoi(tmp.c_str()));
			lData.push_back(atoi(tmp.c_str()));
		} else {
			throw std::runtime_error("Error : invalid input");
		}
	}
}

void Pmergeme::printResult() {
	std::vector<int>::iterator it = vData.begin();
	std::list<int>::iterator it2 = lData.begin();

	std::cout << "vector: ";
	while (it != vData.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	std::cout << "list: ";
	while (it2 != lData.end()) {
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;
}

double Pmergeme::checkTime(time_t startTime) {

	time_t currentTime = time(NULL);
	time_t diff = currentTime - startTime;
	double diffSeconds = static_cast<double>(diff);
	return diffSeconds;	
}