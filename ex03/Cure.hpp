/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:13:49 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 12:53:54 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Cure : public AMateria {
private:
public:
	Cure();
	Cure(const Cure &other);
	Cure& operator=(const Cure &other);
	~Cure();
	
	AMateria* clone() const override;
    void use(ICharacter& target) override;
	
};