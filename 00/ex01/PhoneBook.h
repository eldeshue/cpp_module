
#ifndef CPPMODULE00_EX01_PHONEBOOK_H
#define CPPMODULE00_EX01_PHONEBOOK_H

#define PHONE_BOOK_SIZE 8

#include "Contact.h"

class PhoneBook
{
private:
	Contact array[PHONE_BOOK_SIZE];
	int endPos;
	int size;

public:
	PhoneBook();
	PhoneBook(const PhoneBook &pb);
	virtual ~PhoneBook();
	PhoneBook &operator=(const PhoneBook &rhs);

	void add(const std::string &fN, const std::string &lN, const std::string &pN, const std::string &dS);
	const Contact &search(int idx);
};

#endif
