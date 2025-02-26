/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:27:26 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/16 10:40:23 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

	HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){
		std::cout << name << " has been made." << std::endl;
	}
	
	HumanA::~HumanA(){
		std::cout << name << " has been destroyed." << std::endl;
	}
	
void	HumanA::attack()
{
	std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}