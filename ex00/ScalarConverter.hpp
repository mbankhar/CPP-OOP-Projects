#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:

static void convert(const std::string& literal);

};