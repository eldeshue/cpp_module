
#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.h"

int main(int argc, char* argv[])
{
	// input sanity check
	if (argc != 3)
	{
		std::cerr << "Error : wrong number of arguments\n";
		return -1;
	}

	// second file, DbContext instanciatioin
	BitcoinExchange btc(argv[1]);

	// first file, handling query
	std::fstream input_file_stream(argv[2]);
	std::string line;
	std::getline(input_file_stream, line);
	if (line != "date | value")
	{
		std::cerr << "Error : input file foramt error\n";
		return -1;
	}
	while (std::getline(input_file_stream, line))
	{
		try
		{
			btc.query(line);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
