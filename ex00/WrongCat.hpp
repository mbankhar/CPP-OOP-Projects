/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:24:55 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 10:25:09 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal {
private:

public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat& operator=(const WrongCat &other);
	~WrongCat();

	void	makeSound() const;
};
