
#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

#include "Intern.h"

int main()
{
	Intern i;
	Bureaucrat master(1, "Master_Beureaucrat");
	AForm *forms[4];

	forms[0] = i.makeForm("SHRUBBERY_CREATION_FORM", "target1");
	forms[1] = i.makeForm("ROBOTOMY_REQUEST_FORM", "target2");
	forms[2] = i.makeForm("PRESIDENTIAL_PARDON_FORM", "target3");
	forms[3] = i.makeForm("UNKNOWN_FORM", "target4");

	for (int i = 0; i < 4; ++i)
	{
		if (forms[i] != NULL)
		{
			master.signForm(*forms[i]);
			master.executeForm(*forms[i]);
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		delete forms[i];
	}
}
