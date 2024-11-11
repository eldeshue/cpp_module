
#ifndef PRESIDENTIAL_PARDON_FORM
#define PRESIDENTIAL_PARDON_FORM

#include "AForm.h"

#define PPF_TYPE_NAME "SCHRUBBERY_CREATION_FORM"
#define PPF_SIGN_GRADE 25
#define PPF_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm();
	std::string target;

public:
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
