#include "MutantStack.hpp"
#include<iostream>
#include <list>

void testMutantStack()
{
	std::cout << "==== Testing MutantStack ====" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void testList()
{
	std::cout << "\n==== Testing std::list ====" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	
	std::cout << "Top: " << lst.back() << std::endl;
	lst.pop_back();

	std::cout << "Size: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	testMutantStack();
	// testList();
	return 0;
}
