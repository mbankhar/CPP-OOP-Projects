#include "FordJohnsonSorter.hpp"
#include <algorithm> // for std::swap
#include <vector>
#include <deque>


template <typename Container>
void FordJohnsonSorter::sort(Container &c)
{
	if (c.size() < 2)
		return;

	std::vector<std::pair<int,int>> pairs;
	pairs.reserve(c.size() / 2);

	bool   hasLeftover  = false;
	int    leftoverValue = 0;

	auto it = c.begin();
	while (it != c.end())
	{
		int first = *it;
		++it;
		if (it != c.end())
		{
			int second = *it;
			++it;

			if (first > second)
				std::swap(first, second);

			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			hasLeftover   = true;
			leftoverValue = first;
			break;
		}
	}
	Container mainChain;
	mainChain.clear();

	if (!pairs.empty())
		mainChain.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); i++)
	{
		int val = pairs[i].second;
		auto pos = binaryInsert(mainChain, val);
		mainChain.insert(pos, val);
	}
	for (size_t i = 0; i < pairs.size(); i++)
	{
		int val = pairs[i].first;
		auto pos = binaryInsert(mainChain, val);
		mainChain.insert(pos, val);
	}
	if (hasLeftover)
	{
		auto pos = binaryInsert(mainChain, leftoverValue);
		mainChain.insert(pos, leftoverValue);
	}
	c.clear();
	c.insert(c.end(), mainChain.begin(), mainChain.end());
}

template <typename Container>
typename Container::iterator FordJohnsonSorter::binaryInsert(Container &c, int val)
{
	for (auto it = c.begin(); it != c.end(); ++it)
	{
		if (*it > val)
			return it;
	}
	return c.end();
}

template void FordJohnsonSorter::sort<std::vector<int>>(std::vector<int>&);
template void FordJohnsonSorter::sort<std::deque<int>>(std::deque<int>&);

template std::vector<int>::iterator FordJohnsonSorter::binaryInsert(std::vector<int>&, int);
template std::deque<int>::iterator  FordJohnsonSorter::binaryInsert(std::deque<int>&, int);
