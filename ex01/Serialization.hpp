#pragma once

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct s_Data
{
	std::string text;
	int         number;
} Data;

class Serialization
{
private:

	~Serialization();
	Serialization();
	Serialization(Serialization const & src);
	Serialization & operator=(Serialization const & src);

public:

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

