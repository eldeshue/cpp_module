
#include "PhoneBook.h"
#include <iomanip>

PhoneBook::PhoneBook() : endPos(0), cnt(0) {}

PhoneBook::PhoneBook(const PhoneBook &pb)
{
	endPos = pb.endPos;
	cnt = pb.cnt;
	for (int i = 0; i < cnt; ++i)
	{
		array[i] = pb.array[i];
	}
}

PhoneBook::~PhoneBook() {}

PhoneBook &PhoneBook::operator=(const PhoneBook &rhs)
{
	if (this == &rhs)
		return *this;
	endPos = rhs.endPos;
	cnt = rhs.cnt;
	for (int i = 0; i < cnt; ++i)
	{
		array[i] = rhs.array[i];
	}
	return *this;
}

// range check required
// if the index goes out of range, result is undefined.
void PhoneBook::add(const Contact &c)
{
	array[endPos] = c;
	array[endPos].setIndex(endPos);
	endPos = (endPos + 1) % PHONE_BOOK_SIZE;
	if (cnt < 8)
		cnt++;
}

// range check required
// if the index goes out of range, result is undefined.
const Contact &PhoneBook::getContact(int idx) const
{
	return array[idx % PHONE_BOOK_SIZE];
}

const int &PhoneBook::size() const
{
	return cnt;
}

void PhoneBook::printFormatField(std::ostream &os, const std::string &colum) const
{
	if (colum.size() > 10)
	{
		for (int i = 0; i < 9; ++i)
		{
			os << colum[i];
		}
		os << '.';
	}
	else
	{
		os << std::setw(COLUM_SIZE) << std::right << colum;
	}
}

/*
	formatted output
*/
std::ostream &operator<<(std::ostream &os, const PhoneBook &pb)
{
	for (int i = 0; i < pb.size(); ++i)
	{
		os << std::setw(COLUM_SIZE) << std::right << i << '|';
		pb.printFormatField(os, pb.getContact(i).getFName());
		os << '|';
		pb.printFormatField(os, pb.getContact(i).getLName());
		os << '|';
		pb.printFormatField(os, pb.getContact(i).getNName());
		os << '\n';
	}
	return os << std::endl;
}
