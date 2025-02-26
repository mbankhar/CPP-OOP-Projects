/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:41:05 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/23 12:22:22 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << name << " DiamondTrap Parametrized constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other) {
    *this = other; // Use assignment operator
    std::cout << other.name << " DiamondTrap Copy constructor called" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other); // Copy ClapTrap parts
        FragTrap::operator=(other); // Copy FragTrap parts
        ScavTrap::operator=(other); // Copy ScavTrap parts

        this->name = other.name; // Copy DiamondTrap's name
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;

        std::cout << other.name << " DiamondTrap Copy assignment operator called" << std::endl;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << this->name << " DiamondTrap Destructor called" << std::endl;
}


void DiamondTrap::whoAmI() {
    std::cout << "I am " << this->name << " and ClapTrap name is " << ClapTrap::name << std::endl;
}
