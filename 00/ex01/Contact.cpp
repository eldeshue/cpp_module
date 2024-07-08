
#include "Contact.h"

Contact::Contact() : index(-1), firstName(DEFAULT_STRING_VAL), lastName(DEFAULT_STRING_VAL), nickName(DEFAULT_STRING_VAL),
					 phoneNumber(DEFAULT_STRING_VAL), darkestSecret(DEFAULT_STRING_VAL) {}

Contact::Contact(const Contact &c)
{
	if (this == &c)
		return;
	index = c.index;
	firstName = c.firstName;
	lastName = c.lastName;
	nickName = c.nickName;
	phoneNumber = c.phoneNumber;
	darkestSecret = c.darkestSecret;
}

Contact::~Contact() {}

Contact &Contact::operator=(const Contact &rhs)
{
	if (this == &rhs)
		return;
	index = rhs.index;
	firstName = rhs.firstName;
	lastName = rhs.lastName;
	nickName = rhs.nickName;
	phoneNumber = rhs.phoneNumber;
	darkestSecret = rhs.darkestSecret;
}

void Contact::set(int idx, const std::string &fn, const std::string &ln, const std::string &nn,
				  const std::string &pn, const std::string &ds)
{
	index = idx;
	firstName = fn;
	lastName = ln;
	nickName = nn;
	phoneNumber = pn;
	darkestSecret = ds;
}

/*
	formatted output

	four columm -> index, first name, last name, nick name
*/
std::ostream &Contact::operator<<(std::ostream &os)
{
}
