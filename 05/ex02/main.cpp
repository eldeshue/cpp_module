
#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	// SchrubberyCreationForm test
	std::cout << "Test for SchrubberyCreationForm.\n";
	try
	{
		// no sign, no execute
		Bureaucrat a(148, "a");
		ShrubberyCreationForm s("target1");
		a.signForm(s);
		a.executeForm(s);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	try
	{
		// sign, no execute
		Bureaucrat b(140, "b");
		ShrubberyCreationForm s("target2");
		b.signForm(s);
		b.executeForm(s);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	try
	{
		// sign, execute
		Bureaucrat c(99, "c");
		ShrubberyCreationForm s("target3");
		c.signForm(s);
		c.executeForm(s);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	// RobotomyRequestForm test
	std::cout << "Test for RobotomyRequestForm.\n";
	try
	{
		// no sign, no execute
		Bureaucrat d(100, "d");
		RobotomyRequestForm r("target4");
		d.signForm(r);
		d.executeForm(r);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	try
	{
		// sign, no execute
		Bureaucrat e(55, "e");
		RobotomyRequestForm r("target5");
		e.signForm(r);
		e.executeForm(r);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	try
	{
		// sign, execute
		Bureaucrat f(33, "f");
		RobotomyRequestForm r("target6");
		f.signForm(r);
		f.executeForm(r);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	// PresidentialPardonForm test
	std::cout << "Test for PresidentialPardonForm.\n";
	try
	{
		// no sign, no execute
		Bureaucrat g(29, "g");
		PresidentialPardonForm p("target7");
		g.signForm(p);
		g.executeForm(p);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	try
	{
		// sign, no execute
		Bureaucrat h(21, "h");
		PresidentialPardonForm p("target8");
		h.signForm(p);
		h.executeForm(p);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
	try
	{
		// sign, execute
		Bureaucrat i(1, "i");
		PresidentialPardonForm p("target9");
		i.signForm(p);
		i.executeForm(p);
	}
	catch (...)
	{
		std::cout << "Unhandled error thrown.\n";
	}
}
