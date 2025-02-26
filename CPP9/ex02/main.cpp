#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pm;
		pm.parseArguments(argc, argv);
		pm.printBefore();
		pm.sortContainers();
		pm.printAfter();
		pm.printTimes();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
