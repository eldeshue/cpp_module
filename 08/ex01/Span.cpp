
#include "span.h"
#include <limits>

Span::Span(unsigned int N) : limit(N) {}

Span::Span(Span const& other) : limit(other.limit), numbers(other.numbers) {}

Span::~Span() {}

Span& Span::operator=(Span const& rhs) {
	if (this != &rhs)
	{
		limit = rhs.limit;
		numbers = rhs.numbers;
	}
	return *this;
}

void Span::addNumber(int const n) {
	if (numbers.size() == limit)
		throw std::length_error("size limit exceeded");
	numbers.insert(n);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::range_error("not enough elements");

	int result = std::numeric_limits<int>().max();
	std::multiset<int>::iterator curItr = numbers.begin();
	std::multiset<int>::iterator prevItr = curItr;
	++curItr;
	for (; curItr != numbers.end(); ++curItr, ++prevItr)
		result = std::min(result, *curItr - *prevItr);
	return result;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::range_error("not enough elements");

	return *numbers.rbegin() - *numbers.begin();
}
