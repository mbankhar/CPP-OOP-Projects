/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:38:21 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 12:56:06 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
private:
    std::string name;
    AMateria* inventory[4];

public:
    Character(std::string const & name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    ~Character();

    std::string const & getName() const override;
    void equip(AMateria* m) override;
    void unequip(int idx) override;
    void use(int idx, ICharacter& target) override;
};
