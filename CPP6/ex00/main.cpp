#include "ScalarConverter.hpp"

int	main (int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Not good amount of arguments" << std::endl;
	ScalarConverter::convert(argv[1]); 
}