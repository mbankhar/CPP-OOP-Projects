#include "Array.hpp"


template <typename T>
Array<T>::Array() : elements(nullptr), length(0) {}


template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), length(n) {}


template <typename T>
Array<T>::Array(const Array& other) : elements(nullptr), length(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] elements;

		length = other.length;
		elements = new T[length];
		for (unsigned int i = 0; i < length; ++i)
		{
			elements[i] = other.elements[i];
		}
	}
	return *this;
}


template <typename T>
Array<T>::~Array()
{
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= length)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}


template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= length)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}


template <typename T>
unsigned int Array<T>::size() const
{
	return length;
}
