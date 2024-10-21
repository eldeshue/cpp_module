
#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const int grade, const std::string &name)
try : name(name), grade(grade)
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
catch (const std::exception &e)
{
	// name will be destructed automatically.
	// exception e will be copied.
	std::cerr << e.what() << '\n';
	throw e;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
try : name(other.name), grade(other.grade)
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
catch (const std::exception &e)
{
	// name will be destructed automatically.
	// exception e will be copied.
	std::cerr << e.what() << '\n';
	throw e;
}

Bureaucrat::~Bureaucrat() {};

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
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
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << '.';
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error : grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error : grade too low.";
}
