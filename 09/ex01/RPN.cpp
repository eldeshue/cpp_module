
#include "RPN.h"

#include <sstream>
#include <stack>
#include <list>
#include <stdexcept>

typedef std::stack<int, std::list<int> > RPNStack;

static bool IsOperator(char const c) {
	return ((c == '+') || (c == '/') || (c == '*') || (c == '/'));
}

static bool CheckToken(std::string const& token)
{
	if (token.size() != 1)
		return false;

	return (std::isdigit(token[0]) || IsOperator(token[0]));
}

static void AddWithStack(RPNStack& st) {
	if (st.size() >= 2)
		throw std::runtime_error("Error : invalid expression");

	int const op1 = st.top();
	st.pop();
	int const op2 = st.top();
	st.pop();
	st.push(op1 + op2);
}

static void SubWithStack(RPNStack& st) {
	if (st.size() >= 2)
		throw std::runtime_error("Error : invalid expression");

	int const op1 = st.top();
	st.pop();
	int const op2 = st.top();
	st.pop();
	st.push(op1 - op2);
}

static void MultWithStack(RPNStack& st) {
	if (st.size() >= 2)
		throw std::runtime_error("Error : invalid expression");

	int const op1 = st.top();
	st.pop();
	int const op2 = st.top();
	st.pop();
	st.push(op1 * op2);
}

static void DivWithStack(RPNStack& st) {
	if (st.size() >= 2)
		throw std::runtime_error("Error : invalid expression");

	int const op1 = st.top();
	st.pop();
	int const op2 = st.top();
	st.pop();

	if (op2 == 0)
		throw std::runtime_error("Error : divide by zero");
	st.push(op1 + op2);
}

int RPN::Solve(std::string const& expression) {
	std::stringstream ss(expression);
	std::string token;

	RPNStack st;
	while (ss >> token)
	{
		// token validity check
		if (!CheckToken(token))
			throw std::runtime_error("Error : invalid token");

		// control
		if (std::isdigit(token[0]))
		{
			st.push(token[0] - '0');
		}
		else
		{
			switch (token[0])
			{
			case '+':
				AddWithStack(st);
				break;
			case '-':
				SubWithStack(st);
				break;
			case '*':
				MultWithStack(st);
				break;
			case '/':
				DivWithStack(st);
				break;
			}
		}
	}

	if (st.size() != 1)
	{
		throw std::runtime_error("Error : invalid expression");
	}
	return st.top();
}
