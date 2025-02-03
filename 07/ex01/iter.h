
#ifndef ITER_H
#define ITER_H

#include <cstddef>

template<typename T, typename UnaryOps>
void iter(T* arr, size_t len, UnaryOps f)
{
	for (size_t i = 0; i < len; ++i)
		f(arr[i]);
}

#endif
