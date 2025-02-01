#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	try {
		std::vector<int> vec = {10, 20, 30, 40, 50, 30};
		std::list<int> lst = {5, 15, 25, 35, 45, 15};
		std::deque<int> deq = {3, 1, 2, 3, 4, 5};

		std::cout << "Found in vector at index: " 
				<< std::distance(vec.begin(), easyfind(vec, 30)) << std::endl;

		std::cout << "Found in list at index: " 
				<< std::distance(lst.begin(), easyfind(lst, 15)) << std::endl;

		std::cout << "Found in deque at index: " 
				<< std::distance(deq.begin(), easyfind(deq, 3)) << std::endl;

		std::cout << "Trying to find 100 in vector..." << std::endl;
		easyfind(vec, 100);

	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
