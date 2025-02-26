/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 13:15:01 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/27 13:43:28 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = nullptr;
    }
}
MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
}
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            inventory[i] = (other.inventory[i]) ? other.inventory[i]->clone() : nullptr;
        }
    }
    return *this;
}
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
    }
}
void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m->clone();
            std::cout << "Learned Materia of type: " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << "No empty slot available to learn new Materia" << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i] && inventory[i]->getType() == type) {
            return inventory[i]->clone();
        }
    }
    std::cout << "Materia of type '" << type << "' not found" << std::endl;
    return nullptr;
}
