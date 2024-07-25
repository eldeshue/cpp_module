
#include <iostream>
#include <limits>
#include "PhoneBook.h"

bool inputSanityCheck(const std::string &str)
{
	bool allSpaceFlag = true;

	for (std::string::const_iterator itr = str.begin(); itr != str.end(); itr++)
	{
		if (!std::isprint(*itr))
		{
			std::cerr << "Error : Unprintable input. Go back to read command.\n";
			std::cout << "Available Command : EXIT, ADD, SEARCH.\n";
			return false;
		}
		if (!std::isspace(*itr))
		{
			allSpaceFlag = false;
		}
	}
	if (allSpaceFlag)
	{
		std::cerr << "Error : Can't have empty field. Go back to read command.\n";
		std::cout << "Available Command : EXIT, ADD, SEARCH.\n";
		return false;
	}
	return true;
}

int main()
{
	PhoneBook pb;
	std::string query;
	std::cout << "Welcome to the PhoneBook.\nAvailable Command : EXIT, ADD, SEARCH.\n";
	while (std::getline(std::cin, query))
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
			std::getline(std::cin, query);
			if (!inputSanityCheck(query))
				continue;
			temp.setFName(query);
			std::cout << "Last Name	: ";
			std::getline(std::cin, query);
			if (!inputSanityCheck(query))
				continue;
			temp.setLName(query);
			std::cout << "Nick Name	: ";
			std::getline(std::cin, query);
			if (!inputSanityCheck(query))
				continue;
			temp.setNName(query);
			std::cout << "Phone Number	: ";
			std::getline(std::cin, query);
			if (!inputSanityCheck(query))
				continue;
			temp.setPNum(query);
			std::cout << "Darkest Secret	: ";
			std::getline(std::cin, query);
			if (!inputSanityCheck(query))
				continue;
			temp.setDarkSecret(query);
			pb.add(temp);
		}
		else if (query == "SEARCH")
		{
			int targetIndex = -1;
			std::cout << "SEARCH, list of Contact.\n"
					  << pb << "total " << pb.size() << " Contact available.\n"
					  << "type index of Contact to search : ";
			std::cin >> targetIndex;
			if (std::cin.fail())
			{
				std::cerr << "Error : unexpected type of input.\n";
				std::cin.clear();
			}
			else if (0 > targetIndex || targetIndex >= pb.size())
			{
				std::cerr << "Error : Index out of range.\n";
			}
			else
				std::cout << pb.getContact(targetIndex);
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cerr << "Error : Wrong command. EXIT, ADD, SEARCH are available.\n";
		}
		std::cout << "Available Command : EXIT, ADD, SEARCH.\n";
	}
}
