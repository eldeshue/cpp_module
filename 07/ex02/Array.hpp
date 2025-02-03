
#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <exception>

template<typename T>
class Array
{
private:
	size_t size_;
	T* pData;

public:
	Array() : size_(0), pData(NULL) {}
	Array(Array<T> const& other) : size_(other.size_), pData(new T[size_])
	{
		for (size_t i = 0; i < size_; ++i)
			pData[i] = other[i];
	}
	Array(unsigned int n) : size_(n), pData(new T[size_]) {}
	~Array() { delete[](pData); }

	Array<T>& operator=(Array<T> const& rhs)
	{
		// self assign
		if (this == &rhs)
			return *this;

		// delete prev data
		delete[](pData);

		// assign
		this->size_ = rhs.size_();
		pData = new T[this->size_];
		for (size_t i = 0; i < this->size_; ++i)
			pData[i] = rhs[i];
		return *this;

	}

	T& operator[](int const idx)
	{
		if (idx < 0 || static_cast<size_t>(idx) >= this->size_)
			throw std::exception();
		return pData[idx];
	}

	T const& operator[](int const idx) const
	{
		if (idx < 0 || static_cast<size_t>(idx) >= this->size_)
			throw std::exception();
		return pData[idx];
	}

	size_t size() const { return this->size_; }
};

#endif
