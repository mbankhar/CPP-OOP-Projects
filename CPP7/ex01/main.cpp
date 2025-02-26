#include <iostream>
#include "Iter.hpp"

template <typename T>
void printElement(T& element)
{
	std::cout << element << " ";
}

template <>
void printElement<std::string>(std::string& element)
{
	std::cout << element << " ";
}

void increment(int& x)
{
	x += 1;
}

void incrementDouble(double& x)
{
	x += 1.0;
}

void capitalize(std::string& str)
{
	for (char& c : str) {
		c = toupper(c);
	}
}

int main()
{

	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	iter(intArray, intLength, increment);
	std::cout << "Incremented int array: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	std::string strArray[] = {"hello", "world", "cpp"};
	size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Original string array: ";
	iter(strArray, strLength, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	iter(strArray, strLength, capitalize);
	std::cout << "Capitalized string array: ";
	iter(strArray, strLength, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original double array: ";
	iter(doubleArray, doubleLength, printElement<double>);
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	iter(doubleArray, doubleLength, incrementDouble);
	std::cout << "Incremented double array: ";
	iter(doubleArray, doubleLength, printElement<double>);
	std::cout << std::endl;
	std::cout << "--------------------------------------------" << std::endl;

	return 0;
}