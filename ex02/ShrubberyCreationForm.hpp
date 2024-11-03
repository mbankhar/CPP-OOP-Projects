/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationorm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:31:45 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 16:10:14 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ShrubberyCreationForm.hpp
#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other) = delete;
    ~ShrubberyCreationForm();


    void execute() const override;
};
