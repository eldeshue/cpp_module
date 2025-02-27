
#include "Int.h"

int Int::compare_count = 0;

Int::Int() : value(0) {}
Int::Int(int const n) : value(n) {}
Int::Int(Int const& other) : value(other.value) {}
Int::~Int() {}

Int& Int::operator=(Int const& rhs) {
	if (this != &rhs)
	{
		this->value = rhs.value;
	}
	return *this;
};

bool Int::operator<(Int const& other) const { ++compare_count; return (this->value < other.value); }
bool Int::operator==(Int const& other) const { return (this->value == other.value); };

Int::operator int() { return value; }
Int::operator int() const { return value; }


void Int::SetCompareCnt(int const n) { compare_count = n; }
int Int::GetCompareCnt() { return compare_count; }

std::ostream& operator<<(std::ostream& os, Int const& i) { return os << static_cast<int>(i); }
