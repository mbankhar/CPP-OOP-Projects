/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:27:49 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/16 10:40:55 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

	HumanB::HumanB(std::string name) : name(name), wep(nullptr){
        std::cout << name << " has been made." << std::endl;
    }
	
	HumanB::~HumanB(){
        std::cout << name << " has been destroyed." << std::endl;
    }
	
void HumanB::attack() {
    if (wep) { // Check if weapon is not null
        std::cout << name << " attacks with their " << wep->getType() << std::endl; // Use arrow operator for pointer
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl; // Output if no weapon
    }
}


void	HumanB::setWeapon(Weapon &newweapon){
	wep = &newweapon;
}