/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:08 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/04 10:58:05 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException("Grade too low to execute RobotomyRequestForm.", executor.getName());

    std::cout << "*Drilling noises*" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been successfully robotomized." << std::endl;
    else
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
}