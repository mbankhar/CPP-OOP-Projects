#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cctype>
#include <cmath>

void ScalarConverter::convert(const std::string& literal)
{
	char c;
	int i;
	float f;
	double d;
	bool isImpossible = false;

	try {
		if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		{
			c = literal[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
		}
		else if (literal == "-inf" || literal == "+inf" || literal == "nan")
		{
			throw std::runtime_error("Special double value");
		}
		else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		{
			throw std::runtime_error("Special float value");
		}
		else if (literal.find('.') != std::string::npos)
		{
			if (literal.back() == 'f')
			{
				f = std::stof(literal);
				d = static_cast<double>(f);
				c = static_cast<char>(f);
				i = static_cast<int>(f);
			}
			else
			{
				d = std::stod(literal);
				f = static_cast<float>(d);
				c = static_cast<char>(d);
				i = static_cast<int>(d);
			}
		}
		else
		{
			i = std::stoi(literal);
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		}
	}
	catch (...)
	{
		isImpossible = true;
	}
	std::cout << "char: ";
	if (isImpossible || !std::isprint(c))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << "'" << c << "'" << std::endl;
	}
	std::cout << "int: ";
	if (isImpossible || i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << i << std::endl;
	}
	std::cout << "float: ";
	if (isImpossible)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
	std::cout << "double: ";
	if (isImpossible)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	}
}
