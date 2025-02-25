
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "PmergeMe.h"

int main()
{
	int test[13] = { 4, 2, 3, 43, 566, 22222, 26, 1, 90, 54, 77, 72, 71 };

	std::vector<int> test_input;
	for (int i = 0; i < 13; ++i)
	{
		test_input.push_back(test[i]);
	}

	std::vector<int> result = PmergeMe::Sort(test_input);
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << ' ';
	}
	std::cout << std::endl;
}

/*
int main(int argc, char* argv[]) {
	// get input
	// positive number check, duplicate check

	{
		// first : vector
		// time set
		// sort
		// print
	}

	{
		// second : deque
		// time set
		// sort
		// print
	}
}
*/
