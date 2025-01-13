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

Pmergeme::Pmergeme(int ac, char **av) :size(ac) {
	readInput(av);
	std::cout << "Before: ";
	printResult();
	clock_t vStartTime = clock();
	partitionVector(vData, 0);
	clock_t vEndTime = clock();

	clock_t lStartTime = clock();

	partitionList(lData, 0);
	clock_t lEndTime = clock();
	vTime =  checkTime(vStartTime, vEndTime);
	lTime =  checkTime(lStartTime, lEndTime);

	std::cout << "After: ";
	printResult();
	
	std::cout << "Time to process a range of " << size << " elements with std::vector : "<< vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::list : "<< lTime << " us" << std::endl;

}

void Pmergeme::readInput(char **av) {

	for (int i = 0; i < size; i++) {
		std::string str = av[i + 1];
		std::stringstream ss(str);
		int num;
		ss >> num;
		if (ss.fail()) {
			std::cerr << "Error: invalid input" << std::endl;
			exit(1);
		}
		vData.push_back(std::make_pair(num, i));
		lData.push_back(std::make_pair(num, i));
	}

}

void Pmergeme::printResult() {
	std::vector<std::pair<int, int> >::iterator it = vData.begin();
	std::list<std::pair<int, int> >::iterator it2 = lData.begin();

	while ( it != vData.end() && it2 != lData.end()) {
		if (it->first != it2->first) {
			std::cout << "Error: different values" << std::endl;
			return;
		}
		std::cout << it->first << " ";
		it++;
		it2++;
	}

	
	std::cout << std::endl;
}


double Pmergeme::checkTime(clock_t startTime, clock_t endTime) {
   double diff = static_cast<double>(endTime - startTime) / (CLOCKS_PER_SEC / 1000000);
   return diff;
}


std::vector<std::pair<int, int> > Pmergeme::mergeVector(std::vector<std::pair<int, int> > &mainChain, std::vector<std::pair<int, int> > subChain, int depth) {

	std::vector<std::pair<int, int> > result = mainChain;
	std::vector<int> jArr = makeJacobsthalSequence(mainChain.size());

	// std::cout << "depth: " << depth << std::endl;
	// for(size_t i = 0; i < mainChain.size(); i++) {
	// 	std::cout << mainChain[i].first << " ";
	// }
	// std::cout << std::endl;	
	// for(size_t i = 0; i < subChain.size(); i++) {
	// 	std::cout << subChain[i].first << " ";
	// }
	// std::cout << std::endl;	
	int subIdx = result.begin()->second / int(pow(2, depth));
	result.insert(result.begin(), subChain[subIdx]);
	std::vector<std::pair<int, int> >::iterator it = result.begin() + 1;
	for(size_t i = 1; i < mainChain.size(); i++) {

		// std::cout << "jac : " << jArr[i] << std::endl;
		it = result.begin() + jArr[i] + i;
		// std::cout << "it : " << it->first << std::endl;
		int subIdx = (mainChain.begin() + jArr[i])->second / int(pow(2, depth));
		// std::cout << "subChain[subIdx]: " << subChain[subIdx].first << std::endl;
		std::vector<std::pair<int, int> >::iterator it2 = std::lower_bound(result.begin(), it, subChain[subIdx]);
		result.insert(it2, subChain[subIdx]);
	}
	if (mainChain.size() != subChain.size()) {
		std::vector<std::pair<int, int> >::iterator it2 = std::lower_bound(result.begin(), result.end(), subChain[subChain.size() - 1]);
		result.insert(it2, subChain[subChain.size() - 1]);
	}

	return result;
}

void Pmergeme::partitionVector(std::vector<std::pair<int, int> > &v, int depth) {

	if (v.size() == 1)
		return;
	
	std::vector<std::pair<int, int> > mainChain;
	std::vector<std::pair<int, int> > subChain;

	int idx = 0;
	for(size_t i=0; i < v.size() / 2; i++) {
		if (v[idx].first > v[idx + 1].first) {
			mainChain.push_back(v[idx]);
			subChain.push_back(v[idx + 1]);
		}
		else {
			mainChain.push_back(v[idx + 1]);
			subChain.push_back(v[idx]);
		}
		idx += 2;
	}
	if (v.size() % 2 != 0) {
		subChain.push_back(v[v.size() - 1]);
	}
	depth++;
	partitionVector(mainChain , depth);
	v = mergeVector(mainChain, subChain, depth);

}


std::vector<int> Pmergeme::makeJacobsthalSequence(int length) {

	std::vector<int> jVector;
	int jacobsthal[15];
	jacobsthal[0]= 1;
	jacobsthal[1] = 3;
	for (int i = 2; i < 15; i++) {
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (jacobsthal[i] > length) {
			jacobsthal[i] = length;
			// break;
		}
	}
	jVector.push_back(0);
	if (length > 2) {
		for (int i = 1; i < 15 && jVector.size() != size_t(length); i++) {
			for(int j = jacobsthal[i]; j > jacobsthal[i - 1]; j--) {
				jVector.push_back(j - 1);
				if (jVector.size() == size_t(length)) {
					break;
				}
			}
		}
	} else {
		jVector.push_back(1);
	}
	// std::cout << "Jacobsthal sequence: ";
	// for( size_t i = 0; i < jVector.size(); i++) {
	// 	std::cout << jVector[i] << " ";
	// }
	// std::cout << std::endl;

	return jVector;
}


std::list<std::pair<int, int> >::iterator findInsertionPoint(std::list<std::pair<int, int> > &l, int idx) {

	std::list<std::pair<int, int> >::iterator it = l.begin();
	for(int i = 0; i < idx; i++) {
		it++;
	}
	return it;
}

void Pmergeme::partitionList(std::list<std::pair<int, int> > &l, int depth) {

	if (l.size() == 1)
		return;
	
	std::list<std::pair<int, int> > mainChain;
	std::list<std::pair<int, int> > subChain;
	std::list<std::pair<int, int> >::iterator it = l.begin();

	for(size_t i=0; i < l.size() / 2; i++) {
		std::list<std::pair<int, int> >::iterator itA = it;
		std::list<std::pair<int, int> >::iterator itB = ++it;
		if (itA->first > itB->first) {
			mainChain.push_back(*itA);
			subChain.push_back(*itB);
		}
		else {
			mainChain.push_back(*itB);
			subChain.push_back(*itA);
		}
		it++;
	}
	if (l.size() % 2 != 0) {
		subChain.push_back(*(l.rbegin()));
	}
	depth++;


	// for(std::list<std::pair<int, int> >::iterator it = mainChain.begin(); it != mainChain.end(); it++) {
	// 	std::cout << it->first << " ";
	// }
	// std::cout << std::endl;	

	// for(std::list<std::pair<int, int> >::iterator it = subChain.begin(); it != subChain.end(); it++) {
	// 	std::cout << it->first << " ";
	// }
	// std::cout << std::endl;	

	partitionList(mainChain , depth);
	l = mergeList(mainChain, subChain, depth);
}




std::list<std::pair<int, int> > Pmergeme::mergeList(std::list<std::pair<int, int> > &mainChain, std::list<std::pair<int, int> > subChain, int depth) {

	std::list<std::pair<int, int> > result(mainChain);
	std::vector<int> jArr = makeJacobsthalSequence(mainChain.size());

	int subIdx = result.begin()->second / int(pow(2, depth));
	result.push_front(*findInsertionPoint(subChain, subIdx));

	for(size_t i = 1; i < mainChain.size(); i++) {
		std::list<std::pair<int, int> >::iterator it = findInsertionPoint(result, jArr[i] + i);

		int subIdx = findInsertionPoint(mainChain, jArr[i])->second / int(pow(2, depth));
		std::list<std::pair<int, int> >::iterator it2 = std::lower_bound(result.begin(), it, *findInsertionPoint(subChain, subIdx));
		result.insert(it2, *findInsertionPoint(subChain, subIdx));
	}
	if (mainChain.size() != subChain.size()) {
		std::list<std::pair<int, int> >::iterator it2 = std::lower_bound(result.begin(), result.end(), *(subChain.rbegin()));
		result.insert(it2, *(subChain.rbegin()));
	}
	return result;
}