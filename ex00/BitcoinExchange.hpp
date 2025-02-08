#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>


class BitcoinExchange {
private:
	std::map<std::string, double> ratios;

public:
	bool			loadRatios(const std::string &file);
	void		process(const std::string &file);
	std::string findClosestDate(const std::string &inputDate);
};