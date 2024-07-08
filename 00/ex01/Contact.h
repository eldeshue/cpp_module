
#ifndef CPPMODULE00_EX01_CONTACT_H
#define CPPMODULE00_EX01_CONTACT_H

#include <string>
#include <iostream>

#define DEFAULT_STRING_VAL "DEFAULT STRING VALUE"

class Contact
{
private:
	int index;
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

public:
	Contact();
	Contact(const Contact &c);
	virtual ~Contact();
	Contact &operator=(const Contact &rhs);
	void set(int idx, const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds);

	std::ostream &operator<<(std::ostream &os); // formatted output
};

#endif
