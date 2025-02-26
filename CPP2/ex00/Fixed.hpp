/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:45:40 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/17 10:42:36 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:

	Fixed();

	Fixed(const Fixed &other);

	Fixed& operator=(const Fixed &other);

	~Fixed();

	int getRawBits(void) const;

	void setRawBits(int const raw);
};

#endif
