#include "span.hpp"

Span::Span(unsigned int n) : _size(n) {
	// v.resize(_size);
}

Span::~Span() {
}

Span *Span::operator=(const Span &a) {
	_size = a._size;
	v = a.v;
	return this;
}

Span::Span(const Span &a) {
	*this = a;
}

void Span::addNumber(const int &num) {
	if (v.size() == _size)
		throw std::out_of_range("Span is full");
	v.push_back(num);
}

void Span::addRange(const int &start, const int &end) {
	for (int i = start; i <= end; i++)
	{
		if (v.size() == _size)
			throw std::out_of_range("Span is full");
		v.push_back(i);
	}
}

int Span::shortestSpan() const {
	if (v.size() < 2)
		throw std::out_of_range("Span is too short");
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	int min = INT_MAX;
	for (size_t i = 0; i < tmp.size() - 1; i++)
	{
		min = std::min(min, tmp[i + 1] - tmp[i]);
	}
	return min;
}

int Span::longestSpan() const {
	if (v.size() < 2)
		throw std::out_of_range("Span is too short");
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}