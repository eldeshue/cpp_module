
#include "Form.h"
#include "Bureaucrat.h"

Form::Form(const std::string &n, const int gS, const int gE)
try : name(n), sign(false), gradeToSign(gS), gradeToExecute(gE)
{
	if (gradeToSign > MIN_BUREAUCRAT_GRADE || gradeToExecute > MIN_BUREAUCRAT_GRADE)
	{
		throw Form::GradeTooLowException();
	}
	else if (gradeToSign < MAX_BUREAUCRAT_GRADE || gradeToExecute < MAX_BUREAUCRAT_GRADE)
	{
		throw Form::GradeTooHighException();
	}
}
catch (const std::exception &e)
{
	throw;
}

Form::Form(const Form &other)
try : name(other.name), sign(other.sign), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	if (gradeToSign > MIN_BUREAUCRAT_GRADE || gradeToExecute > MIN_BUREAUCRAT_GRADE)
	{
		throw Form::GradeTooLowException();
	}
	else if (gradeToSign < MAX_BUREAUCRAT_GRADE || gradeToExecute < MAX_BUREAUCRAT_GRADE)
	{
		throw Form::GradeTooHighException();
	}
}
catch (const std::exception &e)
{
	throw;
}

Form::~Form()
{
}

const std::string &Form::getName() const
{
	return name;
}

bool Form::getSign() const
{
	return sign;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Error : grade too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Error : grade too high.";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	return os << f.getName() << "sign ( " << f.getSign() << " ) grade to sign ( " << f.getGradeToSign() << " )";
}
