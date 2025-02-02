#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	using std::stack<T>::c;  

	using iterator = typename std::deque<T>::iterator;
	using reverse_iterator = typename std::deque<T>::reverse_iterator;

	iterator begin() { return c.begin(); }
	iterator end() { return c.end(); }
	reverse_iterator rbegin() { return c.rbegin(); }
	reverse_iterator rend() { return c.rend(); }

};
