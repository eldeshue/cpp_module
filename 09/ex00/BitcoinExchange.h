
#ifndef BITCOIN_EXCHANGE_H
#define BITCOIN_EXCHANGE_H

#include <map>
#include <string>

class BitcoinExchange {
private:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const&);
	BitcoinExchange& operator=(BitcoinExchange const&);

	std::map<std::string, float> db_context_;

public:
	BitcoinExchange(std::string const& db_file_path);

	void query(std::string const& line) const;
};

#endif
