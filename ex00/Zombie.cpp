/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:40 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 10:41:47 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

	Zombie::Zombie(std::string z_name) : name(z_name) {}

	
    Zombie::~Zombie() {
        std::cout << "Zombie " << name << " has been destroyed." << std::endl;}