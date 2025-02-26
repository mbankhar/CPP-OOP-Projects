/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:30:11 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/15 15:36:13 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <iostream>

class Harl {

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:
	Harl();

    ~Harl();

	void	complain(std::string level);
};


#endif