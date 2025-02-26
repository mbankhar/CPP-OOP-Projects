/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:13:59 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 16:38:12 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Ice : public AMateria {
private:
public:
	Ice();
	Ice(const Ice &other);
	Ice& operator=(const Ice &other);
	~Ice();
	
	AMateria* clone() const override;
    void use(ICharacter& target) override;
	
};