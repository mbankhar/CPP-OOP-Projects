/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 11:53:27 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/04 17:46:28 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int y = 0; argv[i][y]; y++)
			{
				if (std::islower(argv[i][y]))
				{
					std::cout << static_cast<char>(std::toupper(argv[i][y]));
				}
				else
				{
					std::cout << argv[i][y];
				}
			}
			std::cout << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}


