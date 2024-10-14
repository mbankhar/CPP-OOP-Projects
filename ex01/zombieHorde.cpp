/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:37:06 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 14:54:24 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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

