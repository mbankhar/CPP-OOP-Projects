/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:13:15 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:42:44 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string _name, int _gradeS, int _gradeE) : _name(_name), _gradeS(_gradeS), _gradeE(_gradeE)
{
	checkGrade(_gradeS, _name);
	checkGrade(_gradeE, _name);
	std::cout << this->_name << " AForm Default constructor called" << std::endl;
}
AForm::AForm(const AForm &other) 
    : _name(other._name), _sign(other._sign), _gradeS(other._gradeS), _gradeE(other._gradeE){
    std::cout << _name << " AForm Copy constructor called" << std::endl;
}
AForm::~AForm()
{
	std::cout << this->_name <<" AForm Desstructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return this->_name;
}
bool		AForm::getSign() const
{
	return _sign;
}
int			AForm::getGradeSign() const
{
	return _gradeS;
}
int			AForm::getGradeExecute() const
{
	return _gradeE;
}
void		AForm::beSigned(Bureaucrat &bureaucrat)
{
	int BGrade = bureaucrat.getGrade();
	bureaucrat.checkGrade(bureaucrat.getGrade(), bureaucrat.getName());
	if (BGrade <= getGradeSign())
	{
		this->_sign = true;
	}
	else
		throw AForm::GradeTooLowException("Grade too low", bureaucrat.getName());
}

void    AForm::checkGrade(int grade, std::string name)
{
	if (grade < 1)
		throw AForm::GradeTooHighException("Grade too high", name);
	else if (grade > 150)
		throw AForm::GradeTooLowException("Grade too low", name);
}
std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
    os << "AForm Name: " << AForm.getName()
       << ", Signed: " << (AForm.getSign() ? "Yes" : "No")
       << ", Grade Required to Sign: " << AForm.getGradeSign()
       << ", Grade Required to Execute: " << AForm.getGradeExecute();
    return os;
}

