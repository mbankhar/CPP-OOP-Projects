/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:12:47 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 13:29:00 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
    std::cout << "AMateria constructor called for type: " << this->type << std::endl;
}
AMateria::AMateria(const AMateria &other) : type(other.type) {
    std::cout << "AMateria copy constructor called for type: " << this->type << std::endl;
}
AMateria& AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        this->type = other.type;
        std::cout << "AMateria copy assignment operator called for type: " << this->type << std::endl;
    }
    return *this;
}
AMateria::~AMateria() {
    std::cout << "AMateria destructor called for type: " << this->type << std::endl;
}
std::string const & AMateria::getType() const {
    return type;
}
void AMateria::use(ICharacter& target) {
    std::cout << "AMateria used on " << target.getName() << std::endl;
}
