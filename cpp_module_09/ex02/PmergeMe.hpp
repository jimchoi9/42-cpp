#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>


class Pmergeme {
	public:
		Pmergeme(std::string &str);
		~Pmergeme();



	
	private:
		std::vector<int> vData;
		std::list<int> lData;
		time_t vStartTime;
		time_t lStartTime;


		Pmergeme();
		Pmergeme &operator=(const Pmergeme &other);
		Pmergeme(const Pmergeme &other);

		void printResult();
		void readInput(std::string &str);
		double checkTime(time_t startTime);




};


#endif