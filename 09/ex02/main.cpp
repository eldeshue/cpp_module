
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "PmergeMe.h"

int main(int argc, char* argv[]) {

	if (argc <= 1)
	{
		std::cerr << "Error : wrong number of argument" << std::endl;
		return -1;
	}

	// get input
	// positive number check, duplicate check
	std::vector<int> input;
	std::cout << "Before : ";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << ' ';
		input.push_back(std::atoi(argv[i]));
	}
	std::cout << std::endl;

	// sanity check
	bool is_minus = (input.back() < 0);
	for (int i = 0; i < input.size() - 1; ++i)
	{
		is_minus |= (input[i] <= 0);
		for (int j = i + 1; j < input.size(); ++j)
		{
			if (input[i] == input[j])
			{
				std::cerr << "Error : not a unique number" << std::endl;
				return -1;
			}
		}
	}
	if (is_minus)
	{
		std::cerr << "Error : not a positive number" << std::endl;
		return -1;
	}

	// input sanity check
	{
		// sort
		clock_t start = clock();
		std::vector<int> result = PmergeMe::Sort(input);
		clock_t end = clock();
		double time = (static_cast<double>(end - start) * 1000) / CLOCKS_PER_SEC;


		// after sort, print
		std::cout << "After : " << result[0];
		for (int i = 1; i < result.size(); ++i)
		{
			if (result[i - 1] > result[i])
			{
				std::cerr << std::endl << "Error : not Sorted" << std::endl;
				return -1;
			}
			std::cout << ' ' << result[i];
		}

		// print time
		std::cout << std::endl << "Time to process a range of " << input.size() << " with std::vector : " << time << "us" << std::endl;
	}

	{
		// second : deque
		std::deque<int> input2(input.begin(), input.end());

		// sort
		clock_t start = clock();
		std::deque<int> result = PmergeMe::Sort(input2);
		clock_t end = clock();
		double time = (static_cast<double>(end - start) * 1000) / CLOCKS_PER_SEC;

		// print time
		std::cout << std::endl << "Time to process a range of " << input.size() << " with std::deque : " << time << "us" << std::endl;
	}
}
