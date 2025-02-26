#pragma once
	
#include <deque>
#include "FordJohnsonSorter.hpp"

class DequeSorter
{
public:
	DequeSorter();
	DequeSorter(const DequeSorter &other);
	DequeSorter &operator=(const DequeSorter &other);
	~DequeSorter();

	void addNumber(int num);
	void sort();
	const std::deque<int>& getData() const;

private:
	std::deque<int> _data;
};
