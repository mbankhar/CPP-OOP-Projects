#include "FordJohnsonSorter.hpp"
#include <algorithm>
#include <vector>
#include <deque>


std::vector<int> generateJacobsthalSequence(size_t n)
{
	std::vector<int> jacobSeq;
	if (n == 0)
		return jacobSeq;

	jacobSeq.push_back(0);
	if (n == 1)
		return jacobSeq;

	jacobSeq.push_back(1);

	for (size_t i = 2; i < n; ++i)
	{
		int next = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
		jacobSeq.push_back(next);
	}

	return jacobSeq;
}

template <typename Container>
void FordJohnsonSorter::sort(Container &c)
{
	if (c.size() < 2)
		return;

	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(c.size() / 2);

	bool hasLeftover = false;
	int leftoverValue = 0;

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
			hasLeftover = true;
			leftoverValue = first;
			break;
		}
	}

	Container mainChain;
	mainChain.clear();
	for (const auto& pair : pairs)
	{
		auto pos = binaryInsert(mainChain, pair.second);
		mainChain.insert(pos, pair.second);
	}

	std::vector<int> jacobSeq = generateJacobsthalSequence(pairs.size());

	std::vector<size_t> insertionOrder;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < jacobSeq.size(); ++i)
	{
		int idx = jacobSeq[i];
		if (idx < static_cast<int>(pairs.size()) && !used[idx])
		{
			insertionOrder.push_back(idx);
			used[idx] = true;
		}
	}
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (!used[i])
			insertionOrder.push_back(i);
	}
	for (size_t k = 0; k < insertionOrder.size(); ++k)
	{
		size_t idx = insertionOrder[k];
		int val = pairs[idx].first;
		if (std::find(mainChain.begin(), mainChain.end(), val) == mainChain.end())
		{
			auto pos = binaryInsert(mainChain, val);
			mainChain.insert(pos, val);
		}
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
	return std::lower_bound(c.begin(), c.end(), val);
}


template void FordJohnsonSorter::sort<std::vector<int>>(std::vector<int>&);
template void FordJohnsonSorter::sort<std::deque<int>>(std::deque<int>&);

template std::vector<int>::iterator FordJohnsonSorter::binaryInsert(std::vector<int>&, int);
template std::deque<int>::iterator  FordJohnsonSorter::binaryInsert(std::deque<int>&, int);
