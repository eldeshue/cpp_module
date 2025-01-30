
#include "Data.h"

Data::Data() : first(0), second(0.0), third(0ULL), fourth(0.0f) {}

Data::Data::Data(Data const& other) :first(other.first), second(other.second), third(other.third), fourth(other.fourth) {}

Data::~Data() {}

Data& Data::operator=(Data const& rhs)
{
	if (this != &rhs)
	{
		first = rhs.first;
		second = rhs.second;
		third = rhs.third;
		fourth = rhs.fourth;
	}
	return *this;
}

bool Data::operator==(Data const& rhs)
{
	return ((first == rhs.first) && (second == rhs.second) && (third == rhs.third) && (fourth == rhs.fourth));
}

std::ostream& operator<<(std::ostream& os, Data const& d)
{
	return os << d.first << ' ' << d.second << ' ' << d.third << ' ' << d.fourth;
}
