/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:49:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/23 12:25:58 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int main() {

    DiamondTrap dt1("DiamondOne");

    std::cout << "Testing DiamondTrap functionality:\n";
    dt1.whoAmI();


    DiamondTrap dt2(dt1);

    std::cout << "\nTesting DiamondTrap Copy Constructor:\n";
    dt2.whoAmI();

    DiamondTrap dt3("AnotherDiamond");
    dt3 = dt1;

    std::cout << "\nTesting DiamondTrap Assignment Operator:\n";
    dt3.whoAmI();
  
    std::cout << "\nTesting Attack Function:\n";
    dt1.ScavTrap::attack("Target");

    std::cout << "\nEnd of main, destructors will be called.\n";

    return 0;
}
