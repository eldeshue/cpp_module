
#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <string>
#include <exception>
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
private:
	const std::string name;
	int grade;
	Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &rhs);

public:
	Bureaucrat(const int grade, const std::string &name);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	const int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
