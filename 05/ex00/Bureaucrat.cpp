
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const int grade, const std::string &name)
try : grade(grade), name(name)
{
	if (grade > MIN_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < MAX_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
catch (std::exception &e)
{
	// name will be destructed automatically.
	throw e;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
try : grade(other.grade), name(other.name)
{
	if (grade > MIN_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < MAX_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
catch (std::exception &e)
{
	// name will be destructed automatically.
	throw e;
}

Bureaucrat::~Bureaucrat() {};

const std::string &Bureaucrat::getName() const
{
	return name;
}

const int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::increaseGrade()
{
	if (grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	--grade;
}

void Bureaucrat::decreaseGrade()
{
	if (grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	++grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << '.';
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error : grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error : grade too low.";
}
