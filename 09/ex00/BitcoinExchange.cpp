
#include "BitcoinExchange.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <limits>

static bool DbContentCheck(std::string const& line)
{
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (!(('0' <= line[i]) && (line[i] <= '9')) && !(line[i] == ',') && !(line[i] == '.') && !(line[i] == '-') && !isblank(line[i]))
			return false;
	}
	return true;
}

static bool InputContentCheck(std::string const& line)
{
	for (size_t i = 0; i < line.size(); ++i)
	{
		if (!(('0' <= line[i]) && (line[i] <= '9')) && !(line[i] == '|') && !(line[i] == '.') && !(line[i] == '-') && !isblank(line[i]))
			return false;
	}
	return true;
}

// db name check
static bool DbNameCheck(std::string const& db_path_name)
{
	size_t const len = db_path_name.size();

	return db_path_name.substr(len - 4) == ".csv";
}

// date format check
static bool DateFormatCheck(std::string const& date)
{
	std::stringstream ss(date);
	int yy, mm, dd;
	char c;

	// parse check
	if (!(ss >> yy >> c >> mm >> c >> dd))
	{
		return false;
	}


	// month check
	if (mm < 1 && 12 < mm)
	{
		return false;
	}

	// date check
	bool const is_leap = ((((yy % 4) == 0) && ((yy % 100) != 0)) || ((yy % 400) == 0));
	if (is_leap && (mm == 2)
		&& !((0 < dd) && (dd <= 29)))	// leap day
	{
		return false;
	}
	if (mm == 2
		&& !((0 < dd) && (dd <= 28)))
	{
		return false;
	}
	if (((mm == 4) || (mm == 6) || (mm == 9) || (mm == 11))
		&& !((0 < dd) && (dd <= 30)))	// 30
	{
		return false;
	}
	if (((mm == 1) || (mm == 3) || (mm == 5) || (mm == 7) || (mm == 8) || (mm == 10) || (mm == 12))
		&& !((0 < dd) && (dd <= 31)))	// 31
	{
		return false;
	}
	return ss.eofbit;
}

// parse database input line
static std::pair<std::string, float> ParseDbLine(std::string const& line)
{
	std::pair<std::string, float> result;

	std::stringstream ss(line);
	if (!std::getline(ss, result.first, ',') || !(ss >> result.second) || !ss.eof())
	{
		// set result as un available value
		result.second = -1.0f;
	}
	return result;
}

// parse query input line
static std::pair<std::string, float> ParseInputLine(std::string const& line)
{
	std::pair<std::string, float> result;
	char c = '\0';

	std::stringstream ss(line);
	if (!InputContentCheck(line) || !(ss >> result.first >> c >> result.second) || c != '|' || !ss.eof())
	{
		throw std::runtime_error("Error : bad input => " + line);
	}
	if (result.second > 1000.0f)
	{
		throw std::runtime_error("Error : too large a number");
	}
	if (result.second < 0.0f)
	{
		throw std::runtime_error("Error : not a poistive number");
	}
	return result;
}

BitcoinExchange::BitcoinExchange(std::string const& db_file_path) {
	// file name check
	if (db_file_path.size() < 4 || !DbNameCheck(db_file_path))
		throw std::runtime_error("Error : wrong db name");

	// file open
	std::fstream db_file_stream(db_file_path.c_str());
	std::string line_buffer;

	// map initialization
	std::getline(db_file_stream, line_buffer);
	if (line_buffer != "date,exchange_rate")
		throw std::runtime_error("Error : db file foramt error");
	while (std::getline(db_file_stream, line_buffer))
	{
		// content check
		if (!DbContentCheck(line_buffer))
			continue;

		// parse line
		std::pair<std::string, float> date_and_value = ParseDbLine(line_buffer);

		// line sanity check
		if (DateFormatCheck(date_and_value.first)
			&& 0.0f <= date_and_value.second && date_and_value.second <= 1000.0f)
		{
			// initialization
			db_context_.insert(date_and_value);
		}
	}
}

void BitcoinExchange::query(std::string const& line) const {
	// format check
	// get date and count
	std::pair<std::string, float> date_and_count = ParseInputLine(line);

	// handling query
	// get exchange rate
	std::map<std::string, float>::const_iterator itr = db_context_.upper_bound(date_and_count.first);
	if (itr == db_context_.begin())
		throw std::out_of_range("Error : db out of index");
	--itr;

	// calculate result
	std::cout << date_and_count.first << " => " << date_and_count.second << " = " << (*itr).second * date_and_count.second << std::endl;
}
