
#include <iostream>
#include "Bureaucrat.h"

int main()
{
	// test1
	try
	{
		Bureaucrat test1(151, "test1");
		std::cout << test1 << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// test 2
	try
	{
		Bureaucrat test2(-1, "test2");
		std::cout << test2 << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// test 3
	try
	{
		Bureaucrat test3(3, "test3");
		for (int i = 0; i < 5; ++i)
		{
			test3.increaseGrade();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// test 4
	try
	{
		Bureaucrat test4(148, "test4");
		for (int i = 0; i < 5; ++i)
		{
			test4.decreaseGrade();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}
