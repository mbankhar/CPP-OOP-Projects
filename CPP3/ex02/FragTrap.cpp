/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:19:58 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 17:34:03 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default") {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << name << " FragTrap Parametrized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << other.name << " FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
		this->hitPoints = 100;
        this->energyPoints = 100;
        this->attackDamage = 30;
        std::cout << other.name << " FragTrap Copy assignment operator called" << std::endl;
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << this->name << " FragTrap Destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFiveGuys() {
    std::cout << "Positive high five request " << std::endl;
}
