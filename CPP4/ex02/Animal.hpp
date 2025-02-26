/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:17:17 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 11:41:04 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>
#include <iostream>

// using std::string;
// using std::cout;

class Animal {
protected:
	std::string type;

public:
	Animal();
	Animal(const Animal &other);
	Animal& operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const = 0;
	std::string	getType() const;

};


#endif