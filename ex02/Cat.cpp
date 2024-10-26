/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:58:51 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 11:15:45 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : CatBrain(new Brain())
{
    type = "Cat";
    std::cout << this->type << " Default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete CatBrain;
    std::cout << this->type << " Destructor called" << std::endl;
}
Cat::Cat(const Cat &other) : CatBrain(new Brain(*other.CatBrain))
{
    this->type = other.type;
    std::cout << this->type << " Copy constructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &other)
{
    if (this != &other) {
        this->type = other.type;
        delete CatBrain;
        CatBrain = new Brain(*other.CatBrain);
        std::cout << this->type << " Copy assignment operator called" << std::endl;
    }
    return *this;
}




	void	Cat::makeSound() const
	{
		std::cout << this->type << " Miau miau" << std::endl;
	}