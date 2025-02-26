/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 12:38:12 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 13:26:19 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;
    }
}
Character::Character(const Character& other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
}
Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : nullptr;
        }
    }
    return *this;
}
Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}
std::string const & Character::getName() const {
    return name;
}
void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        inventory[idx] = nullptr;
}
void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}
