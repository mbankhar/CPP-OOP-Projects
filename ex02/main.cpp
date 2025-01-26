#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "ABC.hpp"


Base* generate()
{
	int random = rand() % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
	else
		std::cout << "Unknown type\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
	}
	catch (std::bad_cast&) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
	}
	catch (std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
	}
	catch (std::bad_cast&) {}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Base *base = generate();
	identify(base);
	identify(*base);

	Base *base_two;
	base_two = generate();
	identify(base_two);
	identify(*base_two);

	Base *base_three;
	base_three = generate();
	identify(base_three);
	identify(*base_three);


	delete base;
	delete base_two;
	delete base_three;
	return 0;
}
