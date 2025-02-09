#include "RPN.hpp"

int	main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Invalid arguments!" << std::endl;
        return 1;
    }

    RPN rpnCalculator(argv[1]);
    rpnCalculator.makeCalculation();
	std::cout << "Result: " << rpnCalculator.getStackNumber() << std::endl;

    return 0;
}
