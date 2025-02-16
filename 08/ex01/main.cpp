
#include <iostream>
#include <vector>
#include "Span.h"

int main()
{
	// test 1
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// test2
	std::vector<int> test(20000);
	for (int i = 0; i < 20000; ++i)
		test[i] = i;
	sp.addNumbers(test.begin(), test.end());
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
