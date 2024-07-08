
#ifndef CPPMODULE00_EX01_PHONEBOOK_H
#define CPPMODULE00_EX01_PHONEBOOK_H

#define PHONE_BOOK_SIZE 8
#define COLUM_SIZE 10

#include "Contact.h"

class PhoneBook
{
private:
	Contact array[PHONE_BOOK_SIZE];
	int endPos;
	int cnt;

public:
	PhoneBook();
	PhoneBook(const PhoneBook &pb);
	virtual ~PhoneBook();
	PhoneBook &operator=(const PhoneBook &rhs);

	void add(const Contact &c);
	const Contact &getContact(int idx) const;
	const int &size() const;

	void PhoneBook::printFormatField(std::ostream &os, const std::string &colum) const;
};

std::ostream &operator<<(std::ostream &os, const PhoneBook &pb);

#endif
