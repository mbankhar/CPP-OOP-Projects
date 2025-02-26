/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:49:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/22 14:19:37 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2(claptrap1);
    ClapTrap claptrap3("ClapTrap3");

    claptrap1.attack("Target1");
    claptrap1.takeDamage(5);
    claptrap1.attack("Target2");
    claptrap1.beRepaired(4);
    claptrap1.attack("Target3");
    claptrap2.attack("Target4");
    claptrap3 = claptrap1;
    claptrap3.attack("Target5");

    return 0;
}
