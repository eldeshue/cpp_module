
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

void print_stdout(int const n)
{
	std::cout << n << ' ';
}

int main()
{
	int test1[10] = { 3, 4, 5, 6, 7, 8, 9, 0, 1, 2 };
	iter(test1, 10, apply_mult_minus_one);
	iter(test1, 10, print_stdout);
	std::cout << std::endl;

	int test2[10] = { -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
	iter(test2, 10, apply_square);
	iter(test2, 10, print_stdout);
	std::cout << std::endl;

}
