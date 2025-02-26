/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:16:33 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/04 10:59:16 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSign())
        throw FormNotSignedException();
    
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException("Grade too low to execute ShrubberyCreationForm.", executor.getName());

    std::ofstream file(_target + "_shrubbery");
    if (file.is_open()) {

        file << "       ###\n";
        file << "      #o###\n";
        file << "    #####o###\n";
        file << "   #o#\\#|#/###\n";
        file << "    ###\\|/#o#\n";
        file << "     # }|{  #\n";
        file << "       }|{\n";
        file.close();

        std::cout << "Shrubbery created for " << _target << std::endl;
    } else {
        std::cerr << "Failed to create file for " << _target << std::endl;
    }
}
