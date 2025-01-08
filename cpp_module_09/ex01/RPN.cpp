#include "RPN.hpp"

RPN::RPN() : _result(0), countDigit(0), countOperator(0) {}

RPN::RPN(std::string &str) : _result(0), countDigit(0), countOperator(0) {
	readInput(str);
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) {
	_calculateStack = other._calculateStack;
	_dataStack = other._dataStack;
	_result = other._result;
	return *this;
}

void RPN::readInput(std::string &str) {
	std::string tmp;
	std::stringstream ss(str);

	while (ss >> tmp) {
		if (checkInput(tmp)){
			if (isdigit(tmp[0])) {
				_calculateStack.push(atoi(tmp.c_str()));
				// std::cout << "push: " << tmp << std::endl;
			}
			else {
				std::string op = tmp;
				if (_calculateStack.size() < 2)
					throw std::runtime_error("Error : invalid input");
				int a = _calculateStack.top();
				_calculateStack.pop();
				int b = _calculateStack.top();
				_calculateStack.pop();
				// std::cout << "a: " << a << " b: " << b << std::endl;
				_calculateStack.push(calculate(op, b, a));
				// std::cout << "push: " << calculate(op, a, b) << std::endl;
			}
		} else {
			throw std::runtime_error("Error : invalid input");
		}
	}
	if (_calculateStack.size() != 1)
		throw std::runtime_error("Error : invalid input");
	std::cout << _calculateStack.top() << std::endl;
	_calculateStack.pop();
}

bool RPN::checkInput(std::string &str) {
	if (str.size() != 1)
		throw std::runtime_error("Error : invalid input");
	if (isdigit(str[0])) {
		countDigit++;
		return true;
	}
	if(isOperator(str)) {
		countOperator++;
		return true;
	}
	throw std::runtime_error("Error : invalid input");
}

bool RPN::isOperator(std::string &str) {
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return true;
	return false;
}

double RPN::calculate(std::string op, int a, int b) {

	double num = 0;
	double a1 = static_cast<double>(a);
	double b1 = static_cast<double>(b);

	if (op == "+") 
		num = a1 + b1;
	else if (op == "-")
		num = a1 - b1;
	else if (op == "*")
		num = a1 * b1;
	else if (op == "/") {
		if (b1 == 0)
			throw std::runtime_error("Error : division by zero");
		num = a1 / b1;
	}
	return (num);
}


