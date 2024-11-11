
#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "AForm.h"

#define SCF_TYPE_NAME "SCHRUBBERY CREATION FORM"
#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
