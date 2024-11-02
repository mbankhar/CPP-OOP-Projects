/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:13:23 by mbankhar          #+#    #+#             */
/*   Updated: 2024/11/02 18:25:42 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <iostream>

class Form {
private:
	std::string const _name;
	bool _sign;
	int	const _gradeS;
	int const _gradeE;
public:
	Form(std::string _name, int _gradeS, int _gradeE);
	Form(const Form &other);
	Form& operator=(const Form &other);
	~Form();
	
	std::string	getName();
	bool		getSign();
	int			getGradeSign();
	int			getGradeExecute();
	void		beSigned();
	void		signForm();


};