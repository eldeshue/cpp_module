
#include <iostream>
#include "RPN.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error : wrong number of argument\n";
		return -1;
	}

	try
	{
		std::cout << RPN::Solve(argv[1]) << std::endl;
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return -1;
	}
}
