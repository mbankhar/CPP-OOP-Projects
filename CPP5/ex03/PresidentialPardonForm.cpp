/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:32:46 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/04 10:56:48 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor called for target: " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getSign())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException("Grade too low to execute PresidentialPardonForm.", executor.getName());

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
