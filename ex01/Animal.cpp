/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:49:25 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/24 15:27:38 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) 
{
	type = "Animal";
	std::cout << this->type << " Default constructor called" << std::endl;
}
Animal::Animal(const Animal &other)
{
	this->type = other.type;
	std::cout << this->type <<" Copy constructor called" << std::endl;
}
Animal& Animal::operator=(const Animal &other)
{
		if (this != &other) {
	this->type = other.type;
	std::cout << this->type << " Copy assignment operator called" << std::endl;
}
return *this;
}
Animal::~Animal()
{
	std::cout <<"Animal Desstructor called" << std::endl;
}


void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}