
#ifndef INTERN_H
#define INTERN_H

#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

class Intern
{
private:
	Intern(const Intern &other);
	Intern &operator=(const Intern &rhs);

public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &formTargetName) const;
};

#endif
