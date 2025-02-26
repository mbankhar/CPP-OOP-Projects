/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 10:40:07 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/10 11:04:15 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

// Constructor initializes the count and oldest contact index
PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

std::string PhoneBook::truncateString(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}
// Add a contact to the phonebook
void PhoneBook::addContact(const Contact& contact) {
    if (!contact.isValid()) {
        std::cout << "Invalid contact details." << std::endl;
        return;
    }

    if (contactCount < 8) {
        // If there are fewer than 8 contacts, just add the contact
        contacts[contactCount] = contact;
        contactCount++;
    } else {
        // If we already have 8 contacts, replace the oldest one
        contacts[oldestContactIndex] = contact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;  // Move to the next oldest
    }

    std::cout << "Contact added successfully!" << std::endl;
}

// Display the contact information by index
void PhoneBook::searchContact(int index) const {
    if (index < 0 || index >= contactCount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    Contact contact = contacts[index];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "Index" << "|" 
              << std::setw(10) << "First Name" << "|" 
              << std::setw(10) << "Last Name" << "|" 
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    for (int i = 0; i < contactCount; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
    }
}



