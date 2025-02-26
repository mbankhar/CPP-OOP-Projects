/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:13:41 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 13:26:32 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << this->type << " Par constructor called" << std::endl;
}
Cure::Cure(const Cure &other) : AMateria(other)
{
	this->type = other.type;
	std::cout << this->type <<" Copy constructor called" << std::endl;
}
Cure& Cure::operator=(const Cure &other)
{
		if (this != &other) {
	AMateria::operator=(other);
	std::cout << this->type << " Copy assignment operator called" << std::endl;
}
return *this;
}
Cure::~Cure()
{
	std::cout << this->type << " Deconstructor called" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}
void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds with Cure *" << std::endl;
}