/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:58:51 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/24 15:23:46 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

	Cat::Cat(void) 
	{
		type = "Cat";
		std::cout << this->type << " Default constructor called" << std::endl;
	}
	Cat::Cat(const Cat &other)
	{
		this->type = other.type;
		std::cout << this->type <<" Copy constructor called" << std::endl;
	}
	Cat& Cat::operator=(const Cat &other)
	{
		 if (this != &other) {
        this->type = other.type;
    	std::cout << this->type << " Copy assignment operator called" << std::endl;
    }
    return *this;
	}
	Cat::~Cat()
	{
		std::cout << this->type <<" Desstructor called" << std::endl;
	}

	void	Cat::makeSound() const
	{
		std::cout << this->type << " Miau miau" << std::endl;
	}