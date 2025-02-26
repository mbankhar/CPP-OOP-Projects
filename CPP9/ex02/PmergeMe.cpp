#include "PmergeMe.hpp"
#include <iostream>
#include <chrono>
#include <limits>
#include <cstdlib>

PmergeMe::PmergeMe()
	: _vecTime(0.0), _deqTime(0.0)
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_original   = other._original;
		this->_vectorSorter = other._vectorSorter;
		this->_dequeSorter  = other._dequeSorter;
		this->_vecTime    = other._vecTime;
		this->_deqTime    = other._deqTime;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{}

void PmergeMe::parseArguments(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.size(); j++)
		{
			if (!isdigit(arg[j]))
				throw std::runtime_error("Invalid input");
		}

		long val = std::strtol(arg.c_str(), NULL, 10);
		if (val <= 0 || val > std::numeric_limits<int>::max())
		{
			throw std::runtime_error("Invalid input");
		}

		int num = static_cast<int>(val);
		_original.push_back(num);

		_vectorSorter.addNumber(num);
		_dequeSorter.addNumber(num);
	}
}

void PmergeMe::sortContainers()
{
	{
		auto start = std::chrono::high_resolution_clock::now();
		_vectorSorter.sort();
		auto end   = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> diff = end - start;
		_vecTime = diff.count();
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		_dequeSorter.sort();
		auto end   = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, std::micro> diff = end - start;
		_deqTime = diff.count();
	}
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _original.size(); i++)
	{
		std::cout << _original[i];
		if (i < _original.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	const std::vector<int>& sortedVec = _vectorSorter.getData();
	std::cout << "After:  ";
	for (size_t i = 0; i < sortedVec.size(); i++)
	{
		std::cout << sortedVec[i];
		if (i < sortedVec.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTimes() const
{
	size_t n = _original.size();
	std::cout << "Time to process a range of " << n << " elements with std::vector : "
			<< _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << n << " elements with std::deque  : "
			<< _deqTime << " us" << std::endl;
}
