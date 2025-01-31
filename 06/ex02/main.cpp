
#include <iostream>
#include "cppex02.h"

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		Base* ptr = generate();
		std::cout << "RTTI test, ptr " << i << " : ";
		identify(ptr);
		std::cout << '\n' << "RTTI test, reference " << i << " : ";
		identify(*ptr);
		std::cout << '\n';
		free(ptr);
	}

}
