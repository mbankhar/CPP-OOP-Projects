/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:14:08 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 13:45:21 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << this->type << " Par constructor called" << std::endl;
}
Ice::Ice(const Ice &other) : AMateria(other)
{
	this->type = other.type;
	std::cout << this->type <<" Copy constructor called" << std::endl;
}
Ice& Ice::operator=(const Ice &other)
{
		if (this != &other) {
	AMateria::operator=(other);
	std::cout << this->type << " Copy assignment operator called" << std::endl;
}
return *this;
}
Ice::~Ice()
{
	std::cout << this->type << " Deconstructor called" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}
void Ice::use(ICharacter& target) {
    std::cout << "Damages " << target.getName() << " with ice *" << std::endl;
}