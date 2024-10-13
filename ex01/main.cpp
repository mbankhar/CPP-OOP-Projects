/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:49:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/06 16:21:29 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
	{
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;

        if (command == "ADD")
		{
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

            std::cout << "First Name: ";
            std::cin >> firstName;
            std::cout << "Last Name: ";
            std::cin >> lastName;
            std::cout << "Nickname: ";
            std::cin >> nickname;
            std::cout << "Phone Number: ";
            std::cin >> phoneNumber;
            std::cout << "Darkest Secret: ";
            std::cin >> darkestSecret;

            Contact newContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            if (newContact.isValid())
			{
                phoneBook.addContact(newContact);
            }
			else
			{
                std::cout << "Error: All fields must be filled in.\n";
            }
        }
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
    		int index;
    		std::cout << "Enter index to search: ";
    		std::cin >> index;

  		  // Clear the newline character left in the buffer after std::cin >>
 		   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   		 phoneBook.searchContact(index);
		}
		else if (command == "EXIT")
		{
            std::cout << "Exiting...\n";
            exit(0);
        }
		else
		{
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return 0;
}


