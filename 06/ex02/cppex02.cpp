
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "cppex02.h"

Base* generate(void)
{
	srand(time(NULL));

	int const randomInt = rand() % 3;
	if (randomInt == 0)
		return new A();
	else if (randomInt == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "A";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "B";
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "C";
	}
	else
	{
		std::cout << "No Match";
	}
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch (const std::exception& e)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B";
		}
		catch (const std::exception& e)
		{
			try
			{
				dynamic_cast<C&>(p);
				std::cout << "C";
			}
			catch (const std::exception& e)
			{
				std::cout << "No Match";
			}
		}
	}
}
