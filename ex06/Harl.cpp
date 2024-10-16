/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbankhar <mbankhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:30:14 by mbankhar          #+#    #+#             */
/*   Updated: 2024/10/15 17:40:57 by mbankhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
    std::cout << "Debug messages contain contextual information. They are mostly "
                 "used for problem diagnosis. "
                 "Example: \"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. "
                 "I really do!\"" << std::endl;
}
void	Harl::info(void)
{
	std::cout << "These messages contain extensive information. They are helpful for"
"tracing program execution in a production environment."
"Example: \"I cannot believe adding extra bacon costs more money. You didn’t put"
"enough bacon in my burger! If you did, I wouldn’t be asking for more!\"" << std::endl;
}
void	Harl::warning(void)
{
	std::cout << "Warning messages indicate a potential issue in the system."
"However, it can be handled or ignored."
"Example: \"I think I deserve to have some extra bacon for free. I’ve been coming for"
"years whereas you started working here since last month.\"" << std::endl;
}
void	Harl::error(void)
{
	std::cout << "These messages indicate an unrecoverable error has occurred."
"This is usually a critical issue that requires manual intervention."
"Example: \"This is unacceptable! I want to speak to the manager now.\"" << std::endl;
}

enum LogLevel { DEBUG, INFO, WARNING, ERROR, NUM_LEVELS };

void Harl::complain(std::string level) {
    void (Harl::*ptr[NUM_LEVELS])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[NUM_LEVELS] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int startLevel = NUM_LEVELS;
    for (int i = 0; i < NUM_LEVELS; i++) {
        if (level == levels[i]) {
            startLevel = i;
            break;
        }
    }
    for (int i = startLevel; i < NUM_LEVELS; i--) {
        switch (i) {
            case DEBUG:
                (this->*ptr[DEBUG])();
                break;
            case INFO:
                (this->*ptr[INFO])();
                break;
            case WARNING:
                (this->*ptr[WARNING])();
                break;
            case ERROR:
                (this->*ptr[ERROR])();
                break;
            default:
                break;
        }
    }
}

Harl::Harl() {
        std::cout << "Harl object created." << std::endl;
    };

    Harl::~Harl() {
        std::cout << "Harl object destroyed." << std::endl;
    };
