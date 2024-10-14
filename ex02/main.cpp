/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:02:32 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/14 15:24:48 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string message = "HI THIS IS BRAIN";
	std::string *pointer = &message;
	std::string &ref = message;

	std::cout << &message << std::endl;
	std::cout << pointer << std::endl;
	std::cout << &ref << std::endl;

	std::cout << message << std::endl;
	std::cout << *pointer << std::endl;
	std::cout << ref << std::endl;
}