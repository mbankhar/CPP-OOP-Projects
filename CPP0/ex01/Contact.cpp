/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:28:43 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/06 15:43:24 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}
// Constructor
Contact::Contact(const std::string& firstName, const std::string& lastName,
                 const std::string& nickname, const std::string& phoneNumber,
                 const std::string& darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

// Getters
std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

// Check if the contact fields are valid (none empty)
bool Contact::isValid() const {
    return !firstName.empty() && !lastName.empty() && !nickname.empty() &&
           !phoneNumber.empty() && !darkestSecret.empty();
}
