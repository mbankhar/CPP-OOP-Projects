/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:27:00 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/16 10:41:49 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

	Weapon::Weapon(std::string type) : type(type) {
		std::cout << type << " has been made." << std::endl;
	}

	Weapon::~Weapon() {
		std::cout << type << " has been destroyed." << std::endl;
	}
	
	const std::string&	Weapon::getType()
	{
		return type;
	}
	void	Weapon::setType(std::string new_one)
	{
		type = new_one;
	}