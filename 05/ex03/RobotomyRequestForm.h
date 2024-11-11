
#ifndef ROBOTOMY_REQUEST_FORM
#define ROBOTOMY_REQUEST_FORM

#include "AForm.h"

#define RRF_TYPE_NAME "ROBOTOMY_REQUEST_FORM"
#define RRF_SIGN_GRADE 72
#define RRF_EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
	std::string target;

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;
	static AForm *clone(const std::string &target);
};

#endif
