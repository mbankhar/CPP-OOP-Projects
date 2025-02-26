/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:41:53 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/26 11:00:51 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Brain {
public:
    std::string ideas[100];
    
    Brain();
    ~Brain();
    Brain(const Brain &other);
    Brain& operator=(const Brain &other);
};

