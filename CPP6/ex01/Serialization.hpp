#pragma once

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct s_Data
{
	std::string text;
	int         number;
} Data;

class Serializer
{
private:

	~Serializer();
	Serializer();
	Serializer(Serializer const & src);
	Serializer & operator=(Serializer const & src);

public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

