
#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool sign;
	const int gradeToSign;
	const int gradeToExecute;
	Form();
	Form &operator=(const Form &rhs);

public:
	Form(const std::string &n, const int gS, const int gE);
	Form(const Form &other);
	~Form();

	const std::string &getName() const;
	const bool getSign() const;
	const int getGradeToSign() const;
	const int getGradeToExecute() const;

	void beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
