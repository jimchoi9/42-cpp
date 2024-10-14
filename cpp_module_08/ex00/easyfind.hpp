#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
// #include <algorithm>


class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found";
    }
};

template <typename T>
typename T::iterator easyfind(T t, int find)
{
	typename T::iterator it = std::find(t.begin(), t.end(), find);
    if (it == t.end())
	{

		throw NotFoundException();
	}
        // std::cout << "Element not found" << std::endl;
    return it;
}

#endif

