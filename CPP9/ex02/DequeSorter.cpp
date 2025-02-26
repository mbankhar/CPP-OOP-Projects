#include "DequeSorter.hpp"

DequeSorter::DequeSorter()
{}

DequeSorter::DequeSorter(const DequeSorter &other)
{
	*this = other;
}

DequeSorter &DequeSorter::operator=(const DequeSorter &other)
{
	if (this != &other)
	{
		this->_data = other._data;
	}
	return *this;
}

DequeSorter::~DequeSorter()
{}

void DequeSorter::addNumber(int num)
{
	_data.push_back(num);
}

void DequeSorter::sort()
{
	FordJohnsonSorter::sort(_data);
}

const std::deque<int>& DequeSorter::getData() const
{
	return _data;
}
