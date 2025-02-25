
#include "PmergeMe.h"

#include <stdexcept>
#include <algorithm>
#include <utility>

static int GetFirstFromPair(pii const p) {
	return p.first;
}

static int GetMatchFromPairs(FirstPairContainer const& pairs, int const key) {
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		// there are no duplicates, so the pair is unique
		if (pairs[i].first == key)
			return pairs[i].second;
	}
	return -1;
}

static void InsertValueInRangeOrderly(int const range, int const value, FirstContainer& dest)
{
	// find insert position using upper_bound
	FirstContainer::iterator insert_pos = std::upper_bound(dest.begin(), dest.begin() + range, value);
	dest.insert(insert_pos, value);
}

static void InsertRangeInOrderly(size_t const left, size_t const right, size_t const range,
	FirstPairContainer const& pairs, FirstContainer const& source, FirstContainer& dest)
{
	// insert
	for (size_t i = right - 1; i >= left; --i)
	{
		int const match = GetMatchFromPairs(pairs, source[i]);
		InsertValueInRangeOrderly(range, match, dest);
	}
}

FirstContainer PmergeMe::Sort(FirstContainer const& seq)
{
	// error handling
	if (seq.size() > jacobsthal_seq[JACOBSTHAL_SEQ_MAX - 1])
	{
		throw std::length_error("Error : input size too big");
	}

	// base case
	if (seq.size() == 2)
	{
		FirstContainer sorted_seq = seq;
		if (sorted_seq[0] > sorted_seq[1])
			std::swap(sorted_seq[0], sorted_seq[1]);
		return sorted_seq;
	}

	// making pair -> how about odd?
	FirstPairContainer pair_seq;
	for (size_t i = 0; i < seq.size() / 2; ++i)
	{
		pair_seq.push_back(std::make_pair(std::max(seq[2 * i], seq[2 * i + 1]), std::min(seq[2 * i], seq[2 * i + 1])));
	}

	// transform, get first
	FirstContainer unsorted_bigger_seq;
	std::transform(pair_seq.begin(), pair_seq.end(), std::back_inserter(unsorted_bigger_seq), GetFirstFromPair);

	// sort, recurse
	FirstContainer sorted_seq = Sort(unsorted_bigger_seq);
	FirstContainer result = sorted_seq;

	// merge with insertion, jacobsthal seq
	// first, just push
	result.insert(result.begin(), GetMatchFromPairs(pair_seq, sorted_seq[0]));

	// insert with jacobsthal seq
	for (size_t i = 0; i < JACOBSTHAL_SEQ_MAX - 1; ++i)
	{
		size_t const left = jacobsthal_seq[i];
		size_t const right = jacobsthal_seq[i + 1];
		if (sorted_seq.size() < left)
			break;

		InsertRangeInOrderly(left, right, (1 << (i + 2)) - 1, pair_seq, sorted_seq, result);
	}

	// if odd, insert last
	if (seq.size() & 1)
	{
		InsertValueInRangeOrderly(result.size(), seq.back(), result);
	}

	return result;
}
