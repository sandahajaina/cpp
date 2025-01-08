/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:27:00 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/08 15:34:20 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() const
{
    const char* reset = "\033[0m";
    std::cout << "\033[1;32m";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
            << std::endl;
    std::cout << reset;
}

void Harl::info() const
{
    std::cout << "\033[1;34m";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
            << std::endl;
    std::cout << "\033[1;34m";
}

void Harl::warning() const
{
    std::cout << "\033[1;33m";
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
            << std::endl;
    std::cout << "\033[0m";
}

void Harl::error() const
{
    std::cout << "\033[1;31m";
    std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
    std::cout << "\033[0m";
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

Harl::Harl() {}

Harl::~Harl() {}