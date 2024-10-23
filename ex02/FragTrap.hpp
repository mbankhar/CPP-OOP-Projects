/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:20:09 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 18:29:12 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap : public ClapTrap {
private:
	FragTrap();

public:

	FragTrap(const std::string &name);
	FragTrap(const FragTrap &other);
	FragTrap& operator=(const FragTrap &other);
	~FragTrap();
	
	void attack(const std::string& target);
	void highFiveGuys();
	
};


#endif