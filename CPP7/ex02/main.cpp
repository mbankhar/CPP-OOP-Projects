#include <iostream>
#include "Array.hpp"

int main()
{
	try {

		Array<int> defaultArray;
		std::cout << "Default array size: " << defaultArray.size() << std::endl;


		Array<int> intArray(5);
		std::cout << "intArray size: " << intArray.size() << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i) {
			std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
		}


		Array<int> copiedArray = intArray;
		std::cout << "\nCopied array size: " << copiedArray.size() << std::endl;


		intArray[0] = 42;
		std::cout << "Modified intArray[0] = " << intArray[0] << std::endl;
		std::cout << "CopiedArray[0] = " << copiedArray[0] << " (should not change)" << std::endl;


		std::cout << "\nAccessing out-of-bounds index:" << std::endl;
		std::cout << intArray[10] << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
