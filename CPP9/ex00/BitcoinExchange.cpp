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
    std::string date;
    std::string valueStr;
    double value;

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date.erase(date.find_last_not_of(" ") + 1);
            valueStr.erase(0, valueStr.find_first_not_of(" "));

            if (!validateDate(date))
            {
                std::cerr << "Error: invalid date format => " << date << std::endl;
                continue;
            }

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
bool BitcoinExchange::validateDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (...) {
		return false;
	}

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1])
		return false;

	if (month == 2 && day == 29)
	{
		if (!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
			return false;
	}

	return true;
}
