#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T t, int find)
{
	typename T::iterator it = std::find(t.begin(), t.end(), find);
    if (it == t.end())
	{
		throw std::out_of_range(std::string("Element not found"));
	}
    return it;
}

#endif

