#ifndef SPAN_CPP
# define SPAN_CPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {

	private :
		Span();
		size_t _size;
		std::vector<int> v;
	public :

		Span(unsigned int n);
		~Span();
		Span(const Span &a);
		Span *operator=(const Span &a);

		void addNumber(const int &num);
		void addRange(const int &start, const int &end);
		int shortestSpan() const;
		int longestSpan() const;
};

#endif