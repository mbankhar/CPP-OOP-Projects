/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:27:00 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 16:49:16 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

	Weapon::Weapon(std::string type) : type(type) {}

	Weapon::~Weapon() {}
	
	const std::string&	Weapon::getType()
	{
		return type;
	}
	void	Weapon::setType(std::string new_one)
	{
		type = new_one;
	}