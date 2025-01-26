#include "Serialization.hpp"

int main()
{

	Data myData;
	myData.number = 123;
	myData.text = "Serialization Test String";


	std::cout << "Original Data:" << std::endl;
	std::cout << "Number: " << myData.number << std::endl;
	std::cout << "Text: " << myData.text << std::endl;


	uintptr_t serialized = Serializer::serialize(&myData);
	std::cout << "\nSerialized value (uintptr_t): " << serialized << std::endl;


	Data* deserializedData = Serializer::deserialize(serialized);

	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "Number: " << deserializedData->number << std::endl;
	std::cout << "Text: " << deserializedData->text << std::endl;

	if (deserializedData == &myData)
	{
		std::cout << "\nTest Passed: Deserialized pointer matches the original pointer." << std::endl;
	}
	else
	{
		std::cout << "\nTest Failed: Deserialized pointer does not match the original pointer." << std::endl;
	}

	return 0;
}
