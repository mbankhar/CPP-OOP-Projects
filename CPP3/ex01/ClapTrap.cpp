/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:49:52 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 16:14:18 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << name << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
	std::cout << name << "Parametarized constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage){
	std::cout << name <<" Copy constructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    	std::cout << name << " Copy assignment operator called" << std::endl;
    }
    return *this;
}
ClapTrap::~ClapTrap(){
	std::cout << name << " Default destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints -= 1;
    	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
	else
	{
		std::cout << "ClapTrap " << this->name << " Not enough energy" << std::endl;
		return;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoints > 0)
	{
    	this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
    	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	}
	else
		return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints != 0)
	{
		this->energyPoints -= 1;
    	this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " is repaired by " << amount << " hit points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " Not enough energy" << std::endl;
		return;
	}
}