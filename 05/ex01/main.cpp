
#include <iostream>
#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	std::cout << "< test 1,2 : Form creation test, wrong executing grade. >\n";
	// test1
	try
	{
		Form test("test1", 45, 151);
		std::cout << test << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	// test 2
	try
	{
		Form test("test2", 45, -33);
		std::cout << test << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "< test 3,4 : Form creation test, wrong signing grade. >\n";
	// test 3
	try
	{
		Form test("test3", 151, 51);
		std::cout << test << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	// test 4
	try
	{
		Form test("test4", -11, 51);
		std::cout << test << '\n';
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	// test 5
	std::cout << "< test 5 : Form Signing tests. >\n";
	{
		Bureaucrat test(32, "Beuro5");
		Form f1("f1", 41, 111);
		Form f2("f2", 32, 111);
		Form f3("f3", 3, 111);
		std::cout << "- Before Signed -\n"
				  << f1 << '\n'
				  << f2 << '\n'
				  << f3 << '\n';
		std::cout << "- Signing -\n";
		test.signForm(f1);
		test.signForm(f2);
		test.signForm(f3);
		std::cout << "- After Signed -\n"
				  << f1 << '\n'
				  << f2 << '\n'
				  << f3 << '\n';
	}
}
