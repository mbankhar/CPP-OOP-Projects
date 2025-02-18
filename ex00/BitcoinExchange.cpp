#include "BitcoinExchange.hpp"



bool	BitcoinExchange::loadRatios(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return false;
	}

	std::string line;
	std::string date;
	double price;
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, ',') && (ss >> price))
		{
			ratios[date] = price;
		}
	}
	file.close();
	return true;
}
void BitcoinExchange::process(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::string	date;
	std::string valueStr;
	double value;
	// std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
		{
			date.erase(date.find_last_not_of(" ") + 1);
			valueStr.erase(0, valueStr.find_first_not_of(" "));

			try {
				value = std::stod(valueStr);
				if (value < 0)
				{
					std::cerr << "Error: not a positive number." << std::endl;
					continue;
				}
				if (value > 1000)
				{
					std::cerr << "Error: too large a number." << std::endl;
					continue;
				}
			}
			catch (...)
			{
				std::cerr << "Error: bad input => " << line << std::endl;
				continue;
			}

			std::string closestDate = findClosestDate(date);
			if (closestDate.empty())
			{
				std::cerr << "Error: no valid date found for " << date << std::endl;
				continue;
			}

			double rate = ratios[closestDate];
			double result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		else
		{
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
	file.close();
}

std::string BitcoinExchange::findClosestDate(const std::string &inputDate)
{
	auto it = ratios.lower_bound(inputDate);
	if (it == ratios.end() || it->first != inputDate)
	{
		if (it == ratios.begin()) return "";
		--it;
	}
	return it->first;
}
