
#ifndef MUTANT_STACK_H
#define MUTANT_STACK_H

#include <stack>
#include <deque>

template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
public:
	typedef typename C::iterator iterator;
	MutantStack<T, C>() : std::stack<T, C>() {}
	MutantStack<T, C>(MutantStack<T, C> const& other) : std::stack<T, C>(other) {}
	~MutantStack<T, C>() {}

	MutantStack<T, C>& operator=(MutantStack<T, C> const& rhs) {
		static_cast<std::stack<T, C> >(*this) = rhs;
	}

	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
};

#endif
