/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:37:15 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 13:27:48 by mbankhar         ###   ########.fr       */
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
	Zombie();

	// Destructor
    ~Zombie();
	
	void announce();
	void setName(std::string z_name); // Setter for name
};

	Zombie* zombieHorde( int N, std::string name );

	
#endif