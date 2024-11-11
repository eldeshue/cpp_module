
#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "AForm.h"

#define SCF_TYPE_NAME "SHRUBBERY_CREATION_FORM"
#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();
	std::string target;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	virtual void execute(Bureaucrat const &executor) const;
	static AForm *clone(const std::string &target);
};

#endif
