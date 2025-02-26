/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:01:44 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 11:09:38 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie{
private:
	std::string name;
public:
	Zombie(std::string z_name);

	// Destructor
    ~Zombie();
	
	void announce();
};

	Zombie* newZombie(std::string name);
	void randomChump( std::string name );

	
#endif