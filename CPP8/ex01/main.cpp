#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "Span.hpp"

// int main()
// {
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
// return 0;
// }

int main()
{
	try {
		std::cout << "🔹 Basic Test" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		
		try
		{
			sp.addNumber(42);
		} catch (const std::exception &e)
		{
			std::cerr << "Exception (addNumber): " << e.what() << std::endl;
		}

		std::cout << "\n🔹 Large Test (10,000 elements)" << std::endl;
		Span largeSpan(10000);
		std::vector<int> bigData;
		
		for (int i = 0; i < 10000; i++)
		{
			bigData.push_back(i * 3);
		}

		largeSpan.addRange(bigData.begin(), bigData.end());

		std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;

		std::cout << "\n🔹 Edge Case: Only One Number (Should Throw Exception)" << std::endl;
		Span oneElement(1);
		oneElement.addNumber(42);

		try
		{
			std::cout << oneElement.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception (shortestSpan): " << e.what() << std::endl;
		}

		try
		{
			std::cout << oneElement.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Exception (longestSpan): " << e.what() << std::endl;
		}

	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected Exception: " << e.what() << std::endl;
	}

	return 0;
}
