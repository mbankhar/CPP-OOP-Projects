/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 11:19:31 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie zombie("Foo");
	Zombie* newZombie( std::string name );
	randomChump("randomChump");
	zombie.announce();
	Zombie* heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete heapZombie;
	return 0;
}