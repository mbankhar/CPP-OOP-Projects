#pragma once

#include "VectorSorter.hpp"
#include "DequeSorter.hpp"
#include <string>
#include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void parseArguments(int argc, char* argv[]);

	void sortContainers();

	void printBefore() const;
	void printAfter() const;
	void printTimes() const;

private:

	std::vector<int>       _original;

	VectorSorter           _vectorSorter;
	DequeSorter            _dequeSorter;

	double                 _vecTime;
	double                 _deqTime;
};

