/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:27:00 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/08 16:58:57 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() const
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
            << std::endl;
}

void Harl::info() const
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
            << std::endl;
}

void Harl::warning() const
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
            << std::endl;
}

void Harl::error() const
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*f[])(void) const = 
    {
        &Harl::debug,        
        &Harl::info,        
        &Harl::warning,        
        &Harl::error      
    };

    std::string levels[4] =
    {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    
    for (size_t i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*f[i])();
            return ;
        }
    }
    
    std::cout << "Unknown level: " << level << std::endl;
}

void Harl::filter(std::string level)
{
    int startLevel = -1;

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            startLevel = i;
            break;
        }
    }

    if (startLevel == -1) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }

    switch (startLevel) {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            this->debug();
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            this->info();
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            this->warning();
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            this->error();
            std::cout << std::endl;
            break;
        default:
            break;
    }
}

Harl::Harl() {}

Harl::~Harl() {}