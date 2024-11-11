
#include "RobotomyRequestForm.h"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
try : AForm(RRF_TYPE_NAME, RRF_SIGN_GRADE, RRF_EXEC_GRADE), target(target)
{
}
catch (const std::exception &e)
{
	throw;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
try : AForm(other), target(other.target)
{
}
catch (const std::exception &e)
{
	throw;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	this->target = rhs.target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkExecutable(executor);

		std::cout << "Makes som drilling noises...\n";
		srand(time(NULL));
		if (rand() & 1)
		{
			std::cout << target << " has been robotomized successfully.\n";
		}
		else
		{
			std::cout << "Robotomizing " << target << " failed.\n";
		}
	}
	catch (const std::exception &e)
	{
		throw;
	}
}
