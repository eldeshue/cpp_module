
#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	Account::_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount << ";closed\n";
}

// increase deposit count
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_amount += deposit;
	Account::_totalAmount += deposit;
	// toto : message
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits << '\n';
}

// if withdrawal amount is bigger than current amount, fails
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	int p_amount = _amount;
	if (withdrawal > _amount) // fail
	{
		std::cout << " index:" << _accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:refused\n";
		return false;
	}
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << " index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals << '\n';
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals << '\n';
}

// print timestamp using ctime
void Account::_displayTimestamp(void)
{
	std::ostringstream osstream;

	osstream << '[';
	time_t rawTime;
	time(&rawTime);
	struct tm *nt = localtime(&rawTime);
	osstream << nt->tm_year + 1900;
	if (nt->tm_mon < 10)
		osstream << 0;
	osstream << nt->tm_mon;
	if (nt->tm_mday < 0)
		osstream << 0;
	osstream << nt->tm_mday;
	osstream << '_';
	if (nt->tm_hour < 10)
		osstream << 0;
	osstream << nt->tm_hour;
	if (nt->tm_min < 10)
		osstream << 0;
	osstream << nt->tm_min;
	if (nt->tm_sec < 10)
		osstream << 0;
	osstream << nt->tm_sec << ']';
	std::cout << osstream.str();
}
