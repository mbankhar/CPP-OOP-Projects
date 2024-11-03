/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:35:36 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:28:00 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;


class Bureaucrat {
private:
    std::string const name;
    int grade;

public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int     getGrade() const;
    void    incrementGrade();
    void    decrementGrade();
    void    checkGrade(int grade, std::string name);
    std::string toString() const;
    void    signForm(Form& form);

class GradeTooLowException : public std::exception {
private:
    std::string fullMessage_;

public:
    GradeTooLowException(const std::string& message, const std::string& name) 
        : fullMessage_("Bureaucrat " + name + ": " + message) {}

    const char* what() const noexcept override {
        return fullMessage_.c_str();
    }
};

class GradeTooHighException : public std::exception {
private:
    std::string fullMessage_;

public:
    GradeTooHighException(const std::string& message, const std::string& name) 
        : fullMessage_("Bureaucrat " + name + ": " + message) {}

    const char* what() const noexcept override {
        return fullMessage_.c_str();
    }
};

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
