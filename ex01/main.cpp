/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:49:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 16:05:03 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {

    ScavTrap scav2("ScavTrap2");

    ScavTrap scav3(scav2);

    scav2.attack("Target1");

    scav2.guardGate();

    scav2 = scav3;

    scav2.attack("Target2");

    return 0;
}


