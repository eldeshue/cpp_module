
#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>

template<typename T>
class Array
{
private:
	size_t size;
	T* pData;

public:
	Array();
	Array(Array<T> const& other);
	Array(unsigned int n);
	~Array();

	Array<T>& operator=(Array<T> const& rhs);

	T& operator[](int const idx);

	size_t size() const;
};

template<typename T>
Array<T>::Array() : size(0), pData(NULL) {}

template<typename T>
Array<T>::Array(Array<T> const& other) : size(other.size), pData(new T[size])
{
	for (size_t i = 0; i < size; ++i)
		pData[i] = other[i];
}

template<typename T>
Array<T>::Array(unsigned int n) : size(n), pData(new T[size]) {}

template<typename T>
Array<T>::~Array() {
	delete[](pData);
}


template<typename T>
Array<T>& Array<T>::operator=(Array<T> const& rhs)
{
	// self assign
	if (this == &rhs)
		return *this;

	// delete prev data
	delete[](pData);

	// assign
	size = rhs.size();
	pData = new T[size];
	for (size_t i = 0; i < size; ++i)
		pData[i] = rhs[i];
	return *this;
}

template<typename T>
T& Array<T>::operator[](int const idx)
{
	if (idx < 0 || idx >= size)
		throw std::exception();
	return pData[idx];
}

template<typename T>
size_t Array<T>::size() const
{
	return size;
}

#endif
