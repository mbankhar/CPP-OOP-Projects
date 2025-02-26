/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:37:22 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/16 11:09:05 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
    int N = 7;
    std::string baseName = "Horde";
	Zombie* horde = zombieHorde( N, baseName);

	for (int i = 0; i < N; ++i) {
        horde[i].announce();  // Assuming announce() is a method of Zombie
    }

    delete[] horde;  // Clean up memory
    return 0;
}


