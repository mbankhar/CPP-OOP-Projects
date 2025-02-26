/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:35:02 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/04 11:02:35 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create bureaucrats with different grades
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 150);

        // Display grades of bureaucrats
        std::cout << alice.getName() << " grade: " << alice.getGrade() << std::endl;
        std::cout << bob.getName() << " grade: " << bob.getGrade() << std::endl;
        std::cout << charlie.getName() << " grade: " << charlie.getGrade() << std::endl;

        // Create forms with different targets
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Robot");
        PresidentialPardonForm pardon("Prisoner");

        // Display grade requirements for forms
        std::cout << "\n--- Form Grade Requirements ---" << std::endl;
        std::cout << shrubbery.getName() << " - Sign: " << shrubbery.getGradeSign()
                  << ", Execute: " << shrubbery.getGradeExecute() << std::endl;
        std::cout << robotomy.getName() << " - Sign: " << robotomy.getGradeSign()
                  << ", Execute: " << robotomy.getGradeExecute() << std::endl;
        std::cout << pardon.getName() << " - Sign: " << pardon.getGradeSign()
                  << ", Execute: " << pardon.getGradeExecute() << std::endl;

        // Test signing and executing with different ranks
        std::cout << "\n--- ShrubberyCreationForm Tests ---" << std::endl;
        charlie.signForm(shrubbery); // Should fail (grade too low)
        alice.executeForm(shrubbery); // Should fail (form not signed)

        std::cout << "\n--- RobotomyRequestForm Tests ---" << std::endl;
        bob.signForm(robotomy); // Should succeed
        bob.executeForm(robotomy); // Should fail due to insufficient grade

        std::cout << "\n--- PresidentialPardonForm Tests ---" << std::endl;
        alice.signForm(pardon); // Only Alice can sign due to grade requirements
        alice.executeForm(pardon); // Should succeed

        std::cout << "\n--- Insufficient Grade for Execution ---" << std::endl;
        bob.executeForm(pardon); // Should fail due to insufficient grade for execution

        std::cout << "\n--- Attempt to Execute Unsigned Form ---" << std::endl;
        PresidentialPardonForm unsignedForm("Unsigned");
        bob.executeForm(unsignedForm); // Should throw exception for unsigned form

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
