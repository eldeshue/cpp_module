
#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;
	AForm();
	AForm &operator=(const AForm &rhs);

protected:
	void checkExecutable(Bureaucrat const &executor) const;

public:
	AForm(const std::string &n, const int gS, const int gE);
	AForm(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	bool getSign() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &b);

	virtual void execute(Bureaucrat const &executor) const = 0; // abstract method

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class ExecutionWithoutSignException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
