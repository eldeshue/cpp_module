
#include <iostream>
#include "Data.h"
#include "Serializer.h"

int main()
{
	Data test1;
	test1.first = 33;
	test1.second = 34.35535;
	test1.third = 123;
	test1.fourth = -2939.9002;

	// simple example
	std::cout << test1 << '\n';
	std::cout << *Serializer::deserialize(Serializer::Serialize(&test1)) << '\n';

	// low level casting example
	std::pair<std::pair<int, double>, std::pair<unsigned long long, float> > test2;
	test2.first.first = 345;
	test2.first.second = 9090.3433;
	test2.second.first = 394394;
	test2.second.second = -24924.000000023;
	std::cout << *Serializer::deserialize(reinterpret_cast<uintptr_t>(&test2)) << '\n';
}
