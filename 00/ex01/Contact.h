
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

	void setIndex(int idx);
	void setFName(const std::string &fn);
	void setLName(const std::string &ln);
	void setNName(const std::string &nn);
	void setPNum(const std::string &pn);
	void setDarkSecret(const std::string &ds);

	const int &getIndex() const;
	const std::string &getFName() const;
	const std::string &getLName() const;
	const std::string &getNName() const;
	const std::string &getPNum() const;
	const std::string &getDarkSecret() const;
};

std::ostream &operator<<(std::ostream &os, const Contact &c); // formatted output

#endif
