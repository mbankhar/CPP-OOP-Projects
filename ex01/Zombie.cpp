/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:37:18 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/16 10:38:07 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

	Zombie::Zombie() {}

	
    Zombie::~Zombie() {
        std::cout << "Zombie " << name << " has been destroyed." << std::endl;}

void Zombie::setName(std::string z_name)
{
	name = z_name;
}

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombies_array = new Zombie[N];
	int i = 0;
	while (i < N)
	{
		new (&zombies_array[i]) Zombie();
		std::string finalname = name + std::to_string(i);
		zombies_array[i].setName(finalname);
		i++;
	}
	return zombies_array;
}
