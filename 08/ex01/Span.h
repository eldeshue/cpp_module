
#ifndef SPAN_H
#define SPAN_H

#include <iterator>
#include <set>
#include <stdexcept>

class Span
{
private:
	std::multiset<int> numbers;
	unsigned int limit;
public:
	explicit Span(unsigned int N);
	Span(Span const& other);
	~Span();

	Span& operator=(Span const& rhs);

	void addNumber(int const n);

	template<typename T>
	void addNumbers(T left, T right) {
		// size check
		size_t const futureSize = numbers.size() + std::distance(left, right);
		if (futureSize > limit)
			throw std::length_error("size limit exceeded");
		// insert
		for (T itr = left; itr != right; ++itr)
			numbers.insert(*left);
	}

	int shortestSpan() const;
	int longestSpan() const;
};

#endif
