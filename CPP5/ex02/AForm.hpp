/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:13:23 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:43:04 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    std::string const _name;
    bool _sign;
    int const _gradeS;
    int const _gradeE;
public:
    AForm(std::string name, int gradeS, int gradeE);
    AForm(const AForm &other);
    AForm& operator=(const AForm &other) = delete;
    virtual ~AForm();

    std::string getName() const;
    bool getSign() const;
    int getGradeSign() const;
    int getGradeExecute() const;
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(const Bureaucrat& executor) const = 0;
	void    checkGrade(int grade, std::string name);

    class GradeTooLowException : public std::exception {
    private:
        std::string fullMessage_;
    public:
        GradeTooLowException(const std::string& message, const std::string& name) 
            : fullMessage_(message + " for " + name) {}
        const char* what() const noexcept override { return fullMessage_.c_str(); }
    };

    class GradeTooHighException : public std::exception {
    private:
        std::string fullMessage_;
    public:
        GradeTooHighException(const std::string& message, const std::string& name) 
            : fullMessage_(message + " for " + name) {}
        const char* what() const noexcept override { return fullMessage_.c_str(); }
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const noexcept override { return "Form is not signed."; }
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
