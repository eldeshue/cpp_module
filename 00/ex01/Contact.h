
#ifndef CPPMODULE00_EX01_CONTACT_H
#define CPPMODULE00_EX01_CONTACT_H

#include <string>
#include <iostream>

class Contact
{
private:
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

public:
	Contact();
	Contact(const Contact &c);
	virtual ~Contact();
	Contact &operator=(const Contact &rhs);

	std::ostream &operator<<(std::ostream &os); // formatted output
};

#endif
