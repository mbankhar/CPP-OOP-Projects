/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:28:42 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/15 14:21:40 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main()
{
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	size_t pos;
	size_t len;
	size_t i = 0;
	size_t y = 0;
	
	std::cout << "Give me a file name" << std::endl;
	std::cin >> filename;
	std::cout << "Give me a string" << std::endl;
	std::cin >> s1;
	std::cout << "Give me another string" << std::endl;
	std::cin >> s2;

	len = s1.length();
	std::ofstream out_file(filename + ".replace");
	if (!out_file.is_open())
	{
		std::cerr << "Could not open file" << std::endl;
		return (1);
	}	
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Could not open file" << std::endl;
		return (1);
	}
	std::ifstream check_file(filename + ".replace");
	if (check_file.is_open())
	{
		std::cout << "File already exists." << std::endl;
    	check_file.close();
    	return 1;
	}
	while (std::getline(file, line))
	{
		while ((pos = line.find(s1)) != std::string::npos)
		{
			line.erase(pos, len);
			line.insert(pos, s2);
			i++;
		}
		out_file << line;
		out_file << std::endl;
		y++;
	}
	if (i == 0)
		std::cout << "Your choosen word was not found" << std::endl;
	if (y == 0)
		std::cout << "Your file is empty" << std::endl;
	out_file.close();
}