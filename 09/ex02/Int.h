
#ifndef INT_H
#define INT_H

#include <iostream>

class Int {
private:
	int value;

	static int compare_count;

public:
	Int();
	Int(int const n);
	Int(Int const& other);
	~Int();

	Int& operator=(Int const& rhs);
	bool operator<(Int const& other) const;
	bool operator==(Int const& other) const;
	operator int();
	operator int() const;

	static void SetCompareCnt(int const n);
	static int GetCompareCnt();
};

std::ostream& operator<<(std::ostream& os, Int const& i);

#endif
