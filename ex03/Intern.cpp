/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:58:29 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/04 13:43:03 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    (void)other;
    std::cout << "Copy Intern constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other) {
    if (this != &other) {

    }
    std::cout << "Copy Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}


AForm* Intern::createShrubberyForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Main makeForm function using a for loop
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Array of form names and their corresponding creation functions
    struct FormEntry {
        const char* name;
        AForm* (*create)(const std::string&);
    } formEntries[] = {
        {"shrubbery creation", &Intern::createShrubberyForm},
        {"robotomy request", &Intern::createRobotomyForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };

    // Iterate over formEntries to find a matching form name
    for (size_t i = 0; i < sizeof(formEntries) / sizeof(FormEntry); ++i) {
        if (formName == formEntries[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return formEntries[i].create(target);  // Call the creation function
        }
    }

    // If no match is found, print an error message
    std::cerr << "Error: Form name '" << formName << "' does not exist." << std::endl;
    return nullptr;
}
