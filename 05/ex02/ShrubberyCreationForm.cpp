
#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
try : AForm(SCF_TYPE_NAME, SCF_SIGN_GRADE, SCF_EXEC_GRADE), target(target)
{
}
catch (const std::exception &e)
{
	throw;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
try : AForm(other), target(other.target)
{
}
catch (const std::exception &e)
{
	throw;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->target = rhs.target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkExecutable(executor);

		// open file and print ASCII tree.
		const std::string outputFileName(target + "_shrubbery");
		std::ofstream outFs(outputFileName.c_str());
		outFs << "                                                         .\n                                              .         ;  \n                 .              .              ;%     ;;   \n                   ,           ,                :;%  %;   \n                    :         ;                   :;%;\'     .,   \n           ,.        %;     %;            ;        %;\'    ,;\n             ;       ;%;  %%;        ,     %;    ;%;    ,%\'\n              %;       %;%;      ,  ;       %;  ;%;   ,%;\' \n               ;%;      %;        ;%;        % ;%;  ,%;\'\n                `%;.     ;%;     %;\'         `;%%;.%;\'\n                 `:;%.    ;%%. %@;        %; ;@%;%\'\n                    `:%;.  :;bd%;          %;@%;\'\n                      `@%:.  :;%.         ;@@%;\'   \n                        `@%.  `;@%.      ;@@%;         \n                          `@%%. `@%%    ;@@%;        \n                            ;@%. :@%%  %@@%;       \n                              %@bd%%%bd%%:;     \n                                #@%%%%%:;;\n                                %@@%%%::;\n                                %@@@%(o);  . \'         \n                                %@@@o%;:(.,\'         \n                            `.. %@@@o%::;         \n                               `)@@@o%::;         \n                                %@@(o)::;        \n                               .%@@@@%::;         \n                               ;%@@@@%::;.          \n                              ;%@@@@%%:;;;. \n                          ...;%@@@@@%%:;;;;,..    Shrubbery, dogwak.\n";
	}
	catch (const std::exception &e)
	{
		throw;
	}
}
