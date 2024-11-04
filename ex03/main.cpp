/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:35:02 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/04 13:57:45 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern someRandomIntern;
    
    // Test 1: Create a RobotomyRequestForm
    std::cout << "\n--- Test 1: Create a RobotomyRequestForm ---" << std::endl;
    AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << *rrf << std::endl; // Assuming AForm has an overloaded << operator for display
        delete rrf; // Clean up after test
    }

    // Test 2: Create a ShrubberyCreationForm
    std::cout << "\n--- Test 2: Create a ShrubberyCreationForm ---" << std::endl;
    AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf) {
        std::cout << *scf << std::endl;
        delete scf; // Clean up after test
    }

    // Test 3: Create a PresidentialPardonForm
    std::cout << "\n--- Test 3: Create a PresidentialPardonForm ---" << std::endl;
    AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    if (ppf) {
        std::cout << *ppf << std::endl;
        delete ppf; // Clean up after test
    }

    // Test 4: Attempt to create a form with an invalid name
    std::cout << "\n--- Test 4: Attempt to create an invalid form ---" << std::endl;
    AForm* invalidForm = someRandomIntern.makeForm("unknown form", "ErrorTarget");
    if (!invalidForm) {
        std::cout << "Form creation failed as expected for invalid form name." << std::endl;
    } else {
        delete invalidForm; // Clean up if a form was somehow created
    }

    // Additional Test: Chain with Bureaucrat
    Bureaucrat alice("Alice", 1);

    std::cout << "\n--- Test 5: Bureaucrat attempts to sign and execute forms ---" << std::endl;
    
    // Bureaucrat signing and executing a ShrubberyCreationForm
    scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (scf) {
        alice.signForm(*scf);
        alice.executeForm(*scf);
        delete scf; // Clean up after test
    }

    // Bureaucrat signing and attempting a RobotomyRequestForm with execution check
    rrf = someRandomIntern.makeForm("robotomy request", "RoboTarget");
    if (rrf) {
        alice.signForm(*rrf);
        alice.executeForm(*rrf);
        delete rrf; // Clean up after test
    }

    // Bureaucrat signing and executing a PresidentialPardonForm
    ppf = someRandomIntern.makeForm("presidential pardon", "Trillian");
    if (ppf) {
        alice.signForm(*ppf);
        alice.executeForm(*ppf);
        delete ppf; // Clean up after test
    }

    return 0;
}
