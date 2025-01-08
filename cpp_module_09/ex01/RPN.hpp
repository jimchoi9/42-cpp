#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
// #include <iomanip>


class RPN {
	public:
		RPN(std::string &str);
		RPN(const RPN &other);
		~RPN();
		RPN &operator=(const RPN &other);

		double calculate(std::string op, int a, int b) ;
		bool isOperator(std::string &str);
	
	private:
		RPN();
		std::stack<int> _calculateStack;
		std::stack<std::string> _dataStack;
		double _result;
		bool checkInput(std::string &str);
		void readInput(std::string &str);
		int countDigit;
		int countOperator;
};

#endif