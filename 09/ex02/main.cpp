
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
	std::vector<Int> input;
	std::cout << "Before : ";
	for (int i = 1; i < argc; ++i)
	{
		std::cout << argv[i] << ' ';
		input.push_back(std::atoi(argv[i]));
	}
	std::cout << std::endl;

	// sanity check
	bool is_minus = (input.back() < static_cast<Int>(0));
	for (size_t i = 0; i < input.size() - 1; ++i)
	{
		if (input[i] <= 0);
		{
			std::cerr << "Error : not a positive number" << std::endl;
			return -1;
		}
	}

	// input sanity check
	{
		Int::SetCompareCnt(0);
		// sort
		clock_t start = clock();
		std::vector<Int> result = PmergeMe::Sort(input);
		clock_t end = clock();
		double time = (static_cast<double>(end - start) * 1000) / CLOCKS_PER_SEC;


		// after sort, print
		std::cout << "After : " << result[0];
		for (size_t i = 1; i < result.size(); ++i)
		{
			if (result[i - 1] > result[i])
			{
				std::cerr << std::endl << "Error : not Sorted" << std::endl;
				return -1;
			}
			std::cout << ' ' << result[i];
		}

		// print time
		std::cout << "\nTime to process a range of " << input.size() << " with std::vector : " << time << "us\n" << "Compare Count : " << Int::GetCompareCnt() << std::endl;
	}

	{
		// second : deque
		std::deque<Int> input2(input.begin(), input.end());

		Int::SetCompareCnt(0);
		// sort
		clock_t start = clock();
		std::deque<Int> result = PmergeMe::Sort(input2);
		clock_t end = clock();
		double time = (static_cast<double>(end - start) * 1000) / CLOCKS_PER_SEC;

		// print time
		std::cout << "Time to process a range of " << input.size() << " with std::deque : " << time << "us\n" << "Compare Count : " << Int::GetCompareCnt() << std::endl;
	}
}
