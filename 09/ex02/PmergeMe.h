
#ifndef PMERGE_ME_H
#define PMERGE_ME_H

#include <vector>
#include <deque>

#include "Int.h"

#define JACOBSTHAL_SEQ_MAX 20

typedef std::vector<Int> FirstContainer;
typedef std::deque<Int> SecondContainer;

typedef std::pair<Int, Int> pii;
typedef std::vector<pii> FirstPairContainer;
typedef std::deque<pii> SecondPairContainer;

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(PmergeMe const&);
	~PmergeMe();
	PmergeMe& operator=(PmergeMe const&);

	static const int jacobsthal_seq[JACOBSTHAL_SEQ_MAX];

public:
	static FirstContainer Sort(FirstContainer const& container);
	static SecondContainer Sort(SecondContainer const& container);
};


#endif

