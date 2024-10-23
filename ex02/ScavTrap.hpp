/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:22:48 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 18:31:41 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap {
private:
	ScavTrap();

public:

	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap& operator=(const ScavTrap &other);
	~ScavTrap();
	
	void attack(const std::string& target);
	void guardGate();
	
};


#endif