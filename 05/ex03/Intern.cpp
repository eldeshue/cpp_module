
#include "Intern.h"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &rhs)
{
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTargetName) const
{
	static const std::string keys[3] = {SCF_TYPE_NAME, RRF_TYPE_NAME, PPF_TYPE_NAME};
	AForm *(*values[3])(const std::string &t) = {&ShrubberyCreationForm::clone, &RobotomyRequestForm::clone, &PresidentialPardonForm::clone};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == keys[i])
		{
			std::cout << "Intern creates " << formName << ".\n";
			return values[i](formTargetName);
		}
	}
	std::cerr << "Intern failed to create " << formName << ", no parameter matched to the key.\n";
	return NULL;
}
