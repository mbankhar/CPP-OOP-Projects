/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:12:56 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 13:40:03 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class ICharacter;

class AMateria
{
	private:
	AMateria();
protected:
	std::string type;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria& operator=(const AMateria &other);
	virtual ~AMateria();
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};