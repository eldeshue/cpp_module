
#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include "AForm.h"

#define SFC_TYPE_NAME "SCHRUBBERY CREATION FORM"
#define SCF_SIGN_GRADE 145
#define SCF_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

	const std::string target;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	virtual void execute(Bureaucrat const &executor) const;
};

#endif
