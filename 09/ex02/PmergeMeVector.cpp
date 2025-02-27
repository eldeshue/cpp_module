
#include "PmergeMe.h"

#include <iostream>

#include <stdexcept>
#include <algorithm>
#include <utility>

static Int GetFirstFromPair(pii const p) {
	return p.first;
}

static Int GetMatchFromMap(FirstPairContainer const& map, Int const key) {
	for (size_t i = 0; i < map.size(); ++i)
	{
		// there are no duplicates, so the pair is unique
		if (map[i].first == key)
		{
			return map[i].second;
		}

	}
	return -1;
}

static void InsertValueInRangeOrderly(Int const limit, Int const value, FirstContainer& dest)
{
	// find insert position using upper_bound
	FirstContainer::iterator insert_pos = std::upper_bound(dest.begin(), dest.begin() + limit, value);
	dest.insert(insert_pos, value);
}

static void InsertRangeInOrderly(size_t const left, size_t const right, size_t const jacobthal_size,
	FirstPairContainer const& pairs, FirstContainer const& source, FirstContainer& dest)
{
	// insert
	for (size_t i = std::min(right, source.size()) - 1; i >= left; --i)
	{
		Int const match = GetMatchFromMap(pairs, source[i]);
		InsertValueInRangeOrderly(std::min(jacobthal_size, dest.size()), match, dest);
	}
}

FirstContainer PmergeMe::Sort(FirstContainer const& seq)
{
	// base case
	if (seq.size() == 1)
	{
		return seq;
	}

	// making pair -> how about odd?
	FirstPairContainer main_sub_map;
	for (size_t i = 0; i < seq.size() / 2; ++i)
	{
		main_sub_map.push_back
		(
			(seq[2 * i] < seq[2 * i + 1]) ?
			(std::make_pair(seq[2 * i + 1], seq[2 * i])) : (std::make_pair(seq[2 * i], seq[2 * i + 1]))
		);
	}

	// transform, get first
	FirstContainer unsorted_bigger_seq;
	std::transform(main_sub_map.begin(), main_sub_map.end(), std::back_inserter(unsorted_bigger_seq), GetFirstFromPair);

	// sort, recurse
	FirstContainer sorted_seq = Sort(unsorted_bigger_seq);

	// merge with insertion, jacobsthal seq
	// first, just push
	FirstContainer result = sorted_seq;
	result.insert(result.begin(), GetMatchFromMap(main_sub_map, sorted_seq[0]));

	// insert with jacobsthal seq
	for (size_t i = 0; i < JACOBSTHAL_SEQ_MAX - 1; ++i)
	{
		size_t const left = jacobsthal_seq[i];
		size_t const right = jacobsthal_seq[i + 1];
		if (sorted_seq.size() < left)
			break;

		InsertRangeInOrderly(left, right, (1 << (i + 2)) - 1, main_sub_map, sorted_seq, result);
	}

	// if odd, insert last
	if (seq.size() & 1)
	{
		InsertValueInRangeOrderly(result.size(), seq.back(), result);
	}


	return result;
}
