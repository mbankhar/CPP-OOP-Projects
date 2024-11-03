/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:13:23 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:43:04 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
#include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;


class Form {
private:
	std::string const _name;
	bool _sign;
	int	const _gradeS;
	int const _gradeE;
public:
	Form(std::string _name, int _gradeS, int _gradeE);
	Form(const Form &other);
	Form& operator=(const Form &other) = delete;
	~Form();
	
	std::string	getName() const;
	bool		getSign() const;
	int			getGradeSign() const;
	int			getGradeExecute() const;
	void		beSigned(Bureaucrat &bureaucrat);
	void    checkGrade(int grade, std::string name);
	
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

std::ostream& operator<<(std::ostream& os, const Form& b);
