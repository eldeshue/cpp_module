
#ifndef EASY_FIND_H
#define EASY_FIND_H

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T const& container, int const target)
{
	typename T::iterator result = std::find(container.begin(), container.end(), target);
	if (result == container.end())
		throw std::runtime_error("target not found");
	return result;
}

#endif
