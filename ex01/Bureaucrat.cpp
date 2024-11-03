/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:35:21 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/03 12:54:56 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	checkGrade(grade, name);
	std::cout << this->name << " Default constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << this->name << " Copy constructor called" << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	std::cout << this->name << " Copy assigment operator called" << std::endl;
	return *this;
}
Bureaucrat::~Bureaucrat() 
{
	std::cout << this->name <<" Desstructor called" << std::endl;
}
std::string	Bureaucrat::getName(void) const
{
	return this->name;
}
int	Bureaucrat::getGrade(void) const
{
	return this->grade;
}
void	Bureaucrat::incrementGrade()
{
	this->grade -= 1;
	checkGrade(grade, this->name);
}
void	Bureaucrat::decrementGrade()
{
	this->grade += 1;
	checkGrade(grade, this->name);
}
void    Bureaucrat::checkGrade(int grade, std::string name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high", name);
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low", name);
}
std::string Bureaucrat::toString() const
{
    return name + ", bureaucrat grade " + std::to_string(grade);
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.toString();
    return os;
}
void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << getName() << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

