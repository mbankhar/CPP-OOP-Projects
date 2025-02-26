#include "VectorSorter.hpp"

VectorSorter::VectorSorter()
{}

VectorSorter::VectorSorter(const VectorSorter &other)
{
	*this = other;
}

VectorSorter &VectorSorter::operator=(const VectorSorter &other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return *this;
}

VectorSorter::~VectorSorter()
{}

void VectorSorter::addNumber(int num)
{
	_data.push_back(num);
}

void VectorSorter::sort()
{
	FordJohnsonSorter::sort(_data);
}

const std::vector<int>& VectorSorter::getData() const
{
	return _data;
}
