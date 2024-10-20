/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:16:19 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/18 13:55:03 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <climits>
#include <cfloat>

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}
Fixed::Fixed(const int number) {
	if (number > (INT_MAX >> _fractionalBits)) {
        throw std::overflow_error("Integer value too large for fixed-point representation");
    }
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = number << _fractionalBits;
}
Fixed::Fixed(const float number) {
	if (number > (FLT_MAX / (1 << _fractionalBits))) {
        throw std::overflow_error("Floating-point value too large for fixed-point representation");
    }
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = roundf(number * (1 << _fractionalBits));
}
Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = other.getRawBits();
}
Fixed& Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _fixedPointValue = other.getRawBits();
    }
    return *this;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fixedPointValue;
}
