#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}
	return *this;
}


Span::~Span() {}


void Span::addNumber(int number)
{
	if (numbers.size() >= N)
	{
		throw std::runtime_error("Span is already full");
	}
	numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
	{
		throw std::runtime_error("Not enough numbers to find a span");
	}

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); i++)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < minSpan)
		{
			minSpan = span;
		}
	}

	return minSpan;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2) {
		throw std::runtime_error("Not enough numbers to find a span");
	}
	return *std::max_element(numbers.begin(), numbers.end()) - 
		*std::min_element(numbers.begin(), numbers.end());
}

void Span::printNumbers() const
{
	std::cout << "Stored numbers: ";
	for (int num : numbers)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}
