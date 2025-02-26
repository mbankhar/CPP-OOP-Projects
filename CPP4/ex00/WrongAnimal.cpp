/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:22:48 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 10:23:21 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) 
{
	type = "WrongAnimal";
	std::cout << this->type << " Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->type = other.type;
	std::cout << this->type <<" Copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
		if (this != &other) {
	this->type = other.type;
	std::cout << this->type << " Copy assignment operator called" << std::endl;
}
return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout <<"WrongAnimal Desstructor called" << std::endl;
}


void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}