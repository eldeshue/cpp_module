
#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>

struct Data
{
	// member variable
	int first;
	double second;
	unsigned long long third;
	float fourth;

	// member function
	Data();
	Data(Data const& other);
	~Data();
	Data& operator=(Data const& rhs);
	bool operator==(Data const& rhs);
};

std::ostream& operator<<(std::ostream& os, Data const& d);


#endif
