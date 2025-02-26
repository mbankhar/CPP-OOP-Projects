/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:30:18 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/15 17:21:19 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	std::string level;
	
	std::cout << "Choose from: DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cin >> level;
	if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR") {
    std::cout << "Invalid level! Please choose from: DEBUG, INFO, WARNING, ERROR." << std::endl;
    return 1;
}

	Harl harl;
	harl.complain(level);
	
}