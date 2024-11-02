/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:35:02 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/01 17:30:14 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat b("George Clooney", 42);
	std::cout << b << std::endl;
    try
    {
        Bureaucrat b1("Alice", 100);
        std::cout << b1.getName() << " has grade: " << b1.getGrade() << std::endl;
        b1.incrementGrade();
        std::cout << b1.getName() << " grade after increment: " << b1.getGrade() << std::endl;
        b1.decrementGrade();
        std::cout << b1.getName() << " grade after decrement: " << b1.getGrade() << std::endl;
        Bureaucrat b2("Bob", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 151);  // This should throw GradeTooLowException
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b4("Daisy", 2);
        b4.incrementGrade();
        std::cout << b4.getName() << " grade after increment to max: " << b4.getGrade() << std::endl;

        b4.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
