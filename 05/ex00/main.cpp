
#include <iostream>
#include "Bureaucrat.h"

int main()
{
	try
	{
		Bureaucrat test1(1, "test1");
		std::cout << test1 << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat test2(151, "test2");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat test3(3, "test3");
		for (int i = 0; i < 5; ++i)
		{
			test3.decreaseGrade();
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
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
