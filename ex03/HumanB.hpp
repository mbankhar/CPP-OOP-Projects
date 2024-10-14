/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:27:55 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 17:49:27 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* wep;
public:

	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &newweapon);
};

#endif