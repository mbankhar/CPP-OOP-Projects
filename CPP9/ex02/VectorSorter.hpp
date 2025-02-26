#pragma once

#include <vector>
#include "FordJohnsonSorter.hpp"

class VectorSorter
{
public:
	VectorSorter();
	VectorSorter(const VectorSorter &other);
	VectorSorter &operator=(const VectorSorter &other);
	~VectorSorter();

	void addNumber(int num);
	void sort();
	const std::vector<int>& getData() const;

private:
	std::vector<int> _data;
};
