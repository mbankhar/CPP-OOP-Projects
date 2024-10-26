/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:22:40 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 10:24:23 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

	WrongCat::WrongCat(void) 
	{
		type = "WrongCat";
		std::cout << this->type << " Default constructor called" << std::endl;
	}
	WrongCat::WrongCat(const WrongCat &other)
	{
		this->type = other.type;
		std::cout << this->type <<" Copy constructor called" << std::endl;
	}
	WrongCat& WrongCat::operator=(const WrongCat &other)
	{
		 if (this != &other) {
        this->type = other.type;
    	std::cout << this->type << " Copy assignment operator called" << std::endl;
    }
    return *this;
	}
	WrongCat::~WrongCat()
	{
		std::cout << this->type <<" Desstructor called" << std::endl;
	}

	void	WrongCat::makeSound() const
	{
		std::cout << this->type << " Wrong Miau miau" << std::endl;
	}