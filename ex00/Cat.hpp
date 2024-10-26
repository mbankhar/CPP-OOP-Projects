/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:17:26 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/24 14:48:44 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal {
private:

public:
	Cat();
	Cat(const Cat &other);
	Cat& operator=(const Cat &other);
	~Cat();

	void	makeSound() const;
};
