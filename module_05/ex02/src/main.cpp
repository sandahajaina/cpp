/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/27 16:41:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

int main()
{
    {
        try
        {
            Form form("f_258", 50, 0); // grade required to execute it < 1
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            Form form("B13", 184, 0); // grade required to sign it > 150
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        try
        {
            Form("appolo_21", 5, 180); // grade required to execute it > 150
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
        Form form("appolo_21", 5, 20);
        Bureaucrat saotra("Saotra", 30);
        std::cout << saotra << '\n';
        std::cout << form << '\n';
        saotra.signForm(form);

        Bureaucrat sanda("Sanda", 1);
        std::cout << sanda << '\n';
        std::cout << form << '\n';
        sanda.signForm(form);
        std::cout << form << '\n';
    }
    
    return  0;
}