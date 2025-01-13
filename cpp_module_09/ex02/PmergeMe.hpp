#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <cmath>
#include <cstdlib>


class Pmergeme {
	public:
		Pmergeme(int ac, char **av);
		~Pmergeme();



	
	private:
		// std::vector<int> vData;
		std::vector<std::pair<int, int> > vData;
		std::list<std::pair<int, int> > lData;
		double vTime;
		double lTime;
		int size;

		Pmergeme();
		Pmergeme &operator=(const Pmergeme &other);
		Pmergeme(const Pmergeme &other);

		void printResult();
		void readInput(char **av);
		double checkTime(clock_t startTime, clock_t endTime);
		std::vector<int> makeJacobsthalSequence(int length);
		std::vector<std::pair<int, int> > mergeVector(std::vector<std::pair<int, int> > &mainChain, std::vector<std::pair<int, int> > subChain, int depth);
		void partitionVector(std::vector<std::pair<int, int> > &v, int depth);

		void partitionList(std::list<std::pair<int, int> > &l, int depth);
std::list<std::pair<int, int> > mergeList(std::list<std::pair<int, int> > &mainChain, std::list<std::pair<int, int> > subChain, int depth);
};


#endif
