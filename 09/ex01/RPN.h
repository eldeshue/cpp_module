
#ifndef RPN_H
#define RPN_H

#include <string>

class RPN
{
private:
	RPN();
	RPN(RPN const&);
	~RPN();
	RPN& operator=(RPN const&);

public:
	static int Solve(std::string const& expression);
};

#endif
