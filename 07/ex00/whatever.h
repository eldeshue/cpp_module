
#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

// swap, copy assign operator needed
template<typename T>
void swap(T& val1, T& val2)
{
	T tmp = val2;
	val2 = val1;
	val1 = tmp;
}

// min, copy-assing and compare operator needed
template<typename T>
T min(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	else // val1 >= val2
		return val2;
}

// max, copy-assing and compare operator needed
template<typename T>
T max(T val1, T val2)
{
	if (val1 > val2)
		return val1;
	else // val1 <= val2
		return val2;
}

#endif
