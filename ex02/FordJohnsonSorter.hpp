#pragma once

#include <vector>
#include <utility>

class FordJohnsonSorter
{
public:
	template <typename Container>
	static void sort(Container &c);

private:
	template <typename Container>
	static typename Container::iterator binaryInsert(Container &c, int val);
};

