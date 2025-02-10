#include "RPN.hpp"
#include <sstream>
#include <cctype>


RPN::RPN(const std::string &line) : line(line) {}
RPN::~RPN() {}
int	RPN::getStackNumber()
{
	if (stackNumbers.empty()) {
		std::cerr << "Error: Stack is empty, no result to return." << std::endl;
		return -1;
	}
	return stackNumbers.top();
}

int RPN::errorCheckLine()
{
	std::istringstream iss(line);
	std::string token;
	int operandCount = 0;

	while (iss >> token)
	{
		if (token.size() == 1 && isdigit(token[0]))
		{
			operandCount++;
		} 
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (operandCount < 2)
			{
				std::cerr << "Error: Not enough operands before operator: " << token << std::endl;
				return 1;
			}
			operandCount--;
		} 
		else
		{
			std::cerr << "Error: Invalid character or number: " << token << std::endl;
			return 1;
		}
	}
	if (operandCount != 1)
	{
		std::cerr << "Error: Invalid expression format. Remaining operands: " << operandCount << std::endl;
		return 1;
	}
	return 0;
}


void RPN::makeCalculation()
{
	if (this->errorCheckLine() != 0)
		return;

	std::istringstream iss(line);
	std::string token;

	while (iss >> token)
	{
		if (isdigit(token[0]) && token.size() == 1)
		{
			stackNumbers.push(token[0] - '0');
		}
		else
		{
			if (stackNumbers.size() < 2)
			{
				std::cerr << "Error: Not enough numbers before operator: " << token << std::endl;
				return;
			}

			int b = stackNumbers.top(); stackNumbers.pop();
			int a = stackNumbers.top(); stackNumbers.pop();

			if (token == "+") stackNumbers.push(a + b);
			else if (token == "-") stackNumbers.push(a - b);
			else if (token == "*") stackNumbers.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return;
				}
				stackNumbers.push(a / b);
			}
		}
	}
	if (stackNumbers.size() != 1)
	{
		std::cerr << "Error: Invalid expression. Remaining numbers: " << stackNumbers.size() << std::endl;
		return;
	}
}
