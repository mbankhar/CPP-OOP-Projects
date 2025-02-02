#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    using std::stack<T>::c;  


    auto begin() { return c.begin(); }
    auto end() { return c.end(); }
    auto rbegin() { return c.rbegin(); }
    auto rend() { return c.rend(); }

};
