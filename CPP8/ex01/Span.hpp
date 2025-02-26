#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span {
private:
	unsigned int N;
	std::vector<int> numbers;

public:

	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	int shortestSpan() const;
	int longestSpan() const;
	

	template <typename Iterator>
	void addRange(Iterator start, Iterator end);

	void printNumbers() const;
};

