
#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
try : AForm(PPF_TYPE_NAME, PPF_SIGN_GRADE, PPF_EXEC_GRADE), target(target)
{
}
catch (const std::exception &e)
{
	throw;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
try : AForm(other), target(other.target)
{
}
catch (const std::exception &e)
{
	throw;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	this->target = rhs.target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkExecutable(executor);

		std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
	}
	catch (const std::exception &e)
	{
		throw;
	}
}

AForm *PresidentialPardonForm::clone(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
