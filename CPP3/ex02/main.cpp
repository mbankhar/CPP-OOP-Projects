/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:49:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 18:30:10 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    FragTrap frag("Fraggy");
    
    frag.attack("Target");
    frag.highFiveGuys();
    

    ScavTrap scav("Scavy");
    scav.attack("Target");
    scav.guardGate();

    return 0;
}

