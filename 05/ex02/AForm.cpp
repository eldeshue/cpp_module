
#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm(const std::string &n, const int gS, const int gE)
try : name(n), sign(false), gradeToSign(gS), gradeToExecute(gE)
{
	if (gradeToSign > MIN_BUREAUCRAT_GRADE || gradeToExecute > MIN_BUREAUCRAT_GRADE)
	{
		throw AForm::GradeTooLowException();
	}
	else if (gradeToSign < MAX_BUREAUCRAT_GRADE || gradeToExecute < MAX_BUREAUCRAT_GRADE)
	{
		throw AForm::GradeTooHighException();
	}
}
catch (const std::exception &e)
{
	throw;
}

AForm::AForm(const AForm &other)
try : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	if (gradeToSign > MIN_BUREAUCRAT_GRADE || gradeToExecute > MIN_BUREAUCRAT_GRADE)
	{
		throw AForm::GradeTooLowException();
	}
	else if (gradeToSign < MAX_BUREAUCRAT_GRADE || gradeToExecute < MAX_BUREAUCRAT_GRADE)
	{
		throw AForm::GradeTooHighException();
	}
}
catch (const std::exception &e)
{
	throw;
}

AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
	return name;
}

bool AForm::getSign() const
{
	return sign;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	sign = true;
}

bool AForm::isExecutable(Bureaucrat const &executor) const
{
	return (sign) && (executor.getGrade() < gradeToExecute);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Error : grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Error : grade too low.";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	return os << f.getName() << ": sign(" << std::boolalpha << f.getSign() << ") grade to sign(" << f.getGradeToSign() << ") grade to execute(" << f.getGradeToExecute() << ")";
}
