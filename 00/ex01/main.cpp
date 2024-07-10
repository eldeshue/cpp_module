
#include <iostream>
#include "PhoneBook.h"

int main()
{
	PhoneBook pb;
	std::string query;
	std::cout << "Welcome to the PhoneBook.\nAvailable Command : EXIT, ADD, SEARCH.\n";
	while (std::cin >> query)
	{
		if (query == "EXIT")
		{
			std::cout << "EXIT, terminate PhoneBook.\n";
			break;
		}
		else if (query == "ADD")
		{
			Contact temp;
			std::cout << "ADD, type each field to init contact.\nFirst Name	: ";
			std::cin >> query;
			temp.setFName(query);
			std::cout << "Last Name	: ";
			std::cin >> query;
			temp.setLName(query);
			std::cout << "Nick Name	: ";
			std::cin >> query;
			temp.setNName(query);
			std::cout << "Phone Number	: ";
			std::cin >> query;
			temp.setPNum(query);
			std::cout << "Darkest Secret	: ";
			std::cin >> query;
			temp.setDarkSecret(query);
			pb.add(temp);
		}
		else if (query == "SEARCH")
		{
			int targetIndex;
			std::cout << "SEARCH, list of Contact.\n"
					  << pb << "type index of Contact to search : ";
			std::cin >> targetIndex;
			if (0 > targetIndex || targetIndex >= pb.size())
			{
				std::cout << "Error : Index out of range.\n";
			}
			else
				std::cout << pb.getContact(targetIndex);
		}
		else
		{
			std::cout << "Error : Wrong command. EXIT, ADD, SEARCH are available.\n";
		}
		std::cout << "Available Command : EXIT, ADD, SEARCH.\n";
	}
}
