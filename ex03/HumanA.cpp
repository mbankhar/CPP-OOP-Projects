/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:27:26 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 17:51:01 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

	HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}
	
	HumanA::~HumanA(){}
	
void	HumanA::attack()
{
	std::cout << name << "attacks with their " << weapon.getType() << std::endl;
}