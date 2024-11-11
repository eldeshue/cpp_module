
#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

int main()
{
	// SchrubberyCreationForm test
	std::cout << "--------------------------------\n";
	std::cout << "< Test for SchrubberyCreationForm >\n";
	try
	{
		// no sign, no execute
		Bureaucrat a(148, "a");
		ShrubberyCreationForm s("target1");
		a.signForm(s);
		a.executeForm(s);
		std::cout << "Target1 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	try
	{
		// sign, no execute
		Bureaucrat b(140, "b");
		ShrubberyCreationForm s("target2");
		b.signForm(s);
		b.executeForm(s);
		std::cout << "Target2 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	try
	{
		// sign, execute
		Bureaucrat c(99, "c");
		ShrubberyCreationForm s("target3");
		c.signForm(s);
		c.executeForm(s);
		std::cout << "Target3 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	// RobotomyRequestForm test
	std::cout << "< Test for RobotomyRequestForm >\n";
	try
	{
		// no sign, no execute
		Bureaucrat d(100, "d");
		RobotomyRequestForm r("target4");
		d.signForm(r);
		d.executeForm(r);
		std::cout << "Target4 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	try
	{
		// sign, no execute
		Bureaucrat e(55, "e");
		RobotomyRequestForm r("target5");
		e.signForm(r);
		e.executeForm(r);
		std::cout << "Target5 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	try
	{
		// sign, execute
		Bureaucrat f(33, "f");
		RobotomyRequestForm r("target6");
		f.signForm(r);
		f.executeForm(r);
		std::cout << "Target6 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	// PresidentialPardonForm test
	std::cout << "< Test for PresidentialPardonForm >\n";
	try
	{
		// no sign, no execute
		Bureaucrat g(29, "g");
		PresidentialPardonForm p("target7");
		g.signForm(p);
		g.executeForm(p);
		std::cout << "Target7 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	try
	{
		// sign, no execute
		Bureaucrat h(21, "h");
		PresidentialPardonForm p("target8");
		h.signForm(p);
		h.executeForm(p);
		std::cout << "Target8 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	try
	{
		// sign, execute
		Bureaucrat i(1, "i");
		PresidentialPardonForm p("target9");
		i.signForm(p);
		i.executeForm(p);
		std::cout << "Target9 Succeeded.\n";
	}
	catch (...)
	{
		std::cout << "Error thrown.\n";
	}
	std::cout << "--------------------------------\n";
	std::cout << "< Robotomy Request Form's random module test >\n";
	Bureaucrat rBuro(1, "Random Beuro");
	RobotomyRequestForm rForm("Random test");
	rBuro.signForm(rForm);
	for (int i = 0; i < 5; ++i)
	{
		rBuro.executeForm(rForm);
	}
}
