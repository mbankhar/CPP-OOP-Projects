#pragma once
#include <iostream>
#include <stack>

class RPN {
private:
    std::string line;
    std::stack<int> stackNumbers;

public:
    RPN(const std::string& line);
    ~RPN();

	int	getStackNumber();
    int errorCheckLine();
    void makeCalculation();
};
