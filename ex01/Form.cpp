/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:13:15 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:42:44 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string _name, int _gradeS, int _gradeE) : _name(_name), _gradeS(_gradeS), _gradeE(_gradeE)
{
	checkGrade(_gradeS, _name);
	checkGrade(_gradeE, _name);
	std::cout << this->_name << " Default constructor called" << std::endl;
}
Form::Form(const Form &other) 
    : _name(other._name), _sign(other._sign), _gradeS(other._gradeS), _gradeE(other._gradeE){
    std::cout << _name << " Copy constructor called" << std::endl;
}
Form::~Form()
{
	std::cout << this->_name <<" Desstructor called" << std::endl;
}

std::string	Form::getName() const
{
	return this->_name;
}
bool		Form::getSign() const
{
	return _sign;
}
int			Form::getGradeSign() const
{
	return _gradeS;
}
int			Form::getGradeExecute() const
{
	return _gradeE;
}
void		Form::beSigned(Bureaucrat &bureaucrat)
{
	int BGrade = bureaucrat.getGrade();
	bureaucrat.checkGrade(bureaucrat.getGrade(), bureaucrat.getName());
	if (BGrade <= getGradeSign())
	{
		this->_sign = true;
	}
	else
		throw Form::GradeTooLowException("Grade too low", bureaucrat.getName());
}

void    Form::checkGrade(int grade, std::string name)
{
	if (grade < 1)
		throw Form::GradeTooHighException("Grade too high", name);
	else if (grade > 150)
		throw Form::GradeTooLowException("Grade too low", name);
}
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form Name: " << form.getName()
       << ", Signed: " << (form.getSign() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeSign()
       << ", Grade Required to Execute: " << form.getGradeExecute();
    return os;
}