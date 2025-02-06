
#include <iostream>
#include <set>
#include <vector>
#include <deque>

#include "easyfind.h"

int main()
{
	// test 1 : vector
	try
	{
		std::vector<int> test1;
		for (int i = 0; i < 30; ++i)
			test1.push_back(i);

		std::cout << "test 1 : " << *easyfind(test1, 22) << '\n';
		std::cout << "test 1 : " << *easyfind(test1, 32) << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// test 2 : deque
	try
	{
		std::deque<int> test2;
		for (int i = 0; i < 30; ++i)
			test2.push_back(i);
		for (int i = 1; i <= 42; ++i)
			test2.push_front(i);

		std::cout << "test 2 : " << *easyfind(test2, 42) << '\n';
		std::cout << "test 2 : " << *easyfind(test2, 52) << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// test 3 : set
	try
	{
		std::set<int> test3;
		for (int i = 1; i <= 42; ++i)
			test3.insert(i);

		std::cout << "test 3 : " << *easyfind(test3, 2) << '\n';
		std::cout << "test 3 : " << *easyfind(test3, 0) << '\n';
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
