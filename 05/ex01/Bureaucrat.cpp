
#include "Bureaucrat.h"
#include "Form.h"

Bureaucrat::Bureaucrat(const int grade, const std::string &name)
try : name(name), grade(grade)
{
	if (grade > MIN_BUREAUCRAT_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < MAX_BUREAUCRAT_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
catch (const std::exception &e)
{
	// name will be destructed automatically.
	// do not throw e, just throw.
	throw;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
try : name(other.name), grade(other.grade)
{
	if (grade > MIN_BUREAUCRAT_GRADE)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < MAX_BUREAUCRAT_GRADE)
	{
		throw Bureaucrat::GradeTooHighException();
	}
}
catch (const std::exception &e)
{
	// name will be destructed automatically.
	// do not throw e, just throw.
	throw;
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
	if (grade == MAX_BUREAUCRAT_GRADE)
		throw Bureaucrat::GradeTooHighException();
	--grade;
}

void Bureaucrat::decreaseGrade()
{
	if (grade == MIN_BUREAUCRAT_GRADE)
		throw Bureaucrat::GradeTooLowException();
	++grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	return os << b.getName() << ", bureaucrat grade " << b.getGrade() << '.';
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat Error : grade too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat Error : grade too low.";
}

void Bureaucrat::signForm(Form &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->name << " signed " << f.getName() << '\n';
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << this->name << " couldn't sign " << f.getName() << " because the grade is too low.\n";
	}
	catch (...)
	{
		std::cerr << this->name << " couldn't sign " << f.getName() << " because of unknown reasons.\n";
	}
}
