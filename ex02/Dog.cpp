/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:24:18 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 11:17:09 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : DogBrain(new Brain())
{
    type = "Dog";
    std::cout << this->type << " Default constructor called" << std::endl;
}
Dog::Dog(const Dog &other) : DogBrain(new Brain(*other.DogBrain))
{
    this->type = other.type;
    std::cout << this->type << " Copy constructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &other)
{
    if (this != &other) {
        this->type = other.type;
        delete DogBrain;
        DogBrain = new Brain(*other.DogBrain);

        std::cout << this->type << " Copy assignment operator called" << std::endl;
    }
    return *this;
}
Dog::~Dog()
{
    delete DogBrain;
    std::cout << this->type << " Destructor called" << std::endl;
}


void	Dog::makeSound() const
{
	std::cout << this->type << " Wau wau" << std::endl;
}