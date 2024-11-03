/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:35:02 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:58:10 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        // Create Bureaucrats
        Bureaucrat highRankBureaucrat("Alice", 1);   // Highest possible grade
        Bureaucrat lowRankBureaucrat("Bob", 150);    // Lowest possible grade

        // Create Forms with valid grades required to sign and execute
        Form importantForm("Top Secret Form", 50, 25);  // Grades required: sign = 50, execute = 25
        Form minorForm("Public Notice Form", 150, 100); // Grades required: sign = 150, execute = 100

        // Display form and bureaucrat information
        std::cout << "Bureaucrats and Forms initialized:\n";
        std::cout << highRankBureaucrat << std::endl;
        std::cout << lowRankBureaucrat << std::endl;
        std::cout << importantForm << std::endl;
        std::cout << minorForm << std::endl;

        // Attempt to sign forms with different Bureaucrats
        std::cout << "\nAttempting to sign forms:\n";
        
        highRankBureaucrat.signForm(importantForm);  // Should succeed
        lowRankBureaucrat.signForm(importantForm);   // Should fail

        highRankBureaucrat.signForm(minorForm);      // Should succeed
        lowRankBureaucrat.signForm(minorForm);       // Should also succeed

        // Verify signed status
        std::cout << "\nForm status after signing attempts:\n";
        std::cout << importantForm << std::endl;
        std::cout << minorForm << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
