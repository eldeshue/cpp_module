
#include "Contact.h"

Contact::Contact() : index(-1), firstName(DEFAULT_STRING_VAL), lastName(DEFAULT_STRING_VAL), nickName(DEFAULT_STRING_VAL),
					 phoneNumber(DEFAULT_STRING_VAL), darkestSecret(DEFAULT_STRING_VAL) {}

Contact::Contact(const Contact &c) : index(c.index), firstName(c.firstName), lastName(c.lastName), nickName(c.nickName),
									 phoneNumber(c.phoneNumber), darkestSecret(c.darkestSecret) {}

Contact::~Contact() {}

Contact &Contact::operator=(const Contact &rhs)
{
	if (this == &rhs)
		return *this;
	index = rhs.index;
	firstName = rhs.firstName;
	lastName = rhs.lastName;
	nickName = rhs.nickName;
	phoneNumber = rhs.phoneNumber;
	darkestSecret = rhs.darkestSecret;
	return *this;
}

void Contact::setIndex(int idx)
{
	index = idx;
}

void Contact::setFName(const std::string &fn)
{
	firstName = fn;
}

void Contact::setLName(const std::string &ln)
{
	lastName = ln;
}

void Contact::setNName(const std::string &nn)
{
	nickName = nn;
}

void Contact::setPNum(const std::string &pn)
{
	phoneNumber = pn;
}

void Contact::setDarkSecret(const std::string &ds)
{
	darkestSecret = ds;
}

const int &Contact::getIndex() const
{
	return index;
}

const std::string &Contact::getFName() const
{
	return firstName;
}

const std::string &Contact::getLName() const
{
	return lastName;
}

const std::string &Contact::getNName() const
{
	return nickName;
}

const std::string &Contact::getPNum() const
{
	return phoneNumber;
}

const std::string &Contact::getDarkSecret() const
{
	return darkestSecret;
}

std::ostream &operator<<(std::ostream &os, const Contact &c)
{
	return os << "first name		: " << c.getFName() << '\n'
			  << "last name		: " << c.getLName() << '\n'
			  << "nick name		: " << c.getNName() << '\n'
			  << "phone number		: " << c.getPNum() << '\n'
			  << "darkest Secret		: " << c.getDarkSecret() << '\n';
}
