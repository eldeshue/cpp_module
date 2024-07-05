
#include <iostream>
#include "PhoneBook.h"

int main()
{
	std::string query;
	while (std::cin >> query)
	{
		if (query == "EXIT")
			break;
		else if (query == "ADD")
		{
			// add
			// need aditional input
		}
		else if (query == "SEARCH")
		{
			// get index
			// print
		}
		else
		{
			// ignore
		}
	}
}
