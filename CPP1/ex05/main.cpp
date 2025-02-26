/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:30:18 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/15 15:38:44 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	std::string level;
	
	std::cout << "Choose from: DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cin >> level;
	Harl harl;
	harl.complain(level);
	
}