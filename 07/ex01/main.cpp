
#include <iostream>
#include <string>

#include "iter.h"

void apply_mult_minus_one(int& n)
{
	n = -1 * n;
}

void apply_square(int& n)
{
	n *= n;
}

template<typename T>
void print_stdout(T const& n)
{
	std::cout << n << ' ';
}

void make_upper(std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
}

int main()
{
	int test1[10] = { 3, 4, 5, 6, 7, 8, 9, 0, 1, 2 };
	iter(test1, 10, apply_mult_minus_one);
	iter(test1, 10, print_stdout<int>);
	std::cout << std::endl;

	int test2[10] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	iter(test2, 10, apply_square);
	iter(test2, 10, print_stdout<int>);
	std::cout << std::endl;

	std::string test3[5] = { "hello", "my", "name", "is", "dogwak" };
	iter(test3, 5, make_upper);
	iter(test3, 5, print_stdout<std::string>);
	std::cout << std::endl;

}
