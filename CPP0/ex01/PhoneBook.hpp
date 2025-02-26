/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:45:58 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/06 16:25:27 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int oldestContactIndex;
	    // Helper function to truncate strings for display
    std::string truncateString(const std::string& str) const;

public:
	PhoneBook();
	void addContact(const Contact& contact);
	void searchContact(int index) const;
	void displayContacts() const;
};

#endif 