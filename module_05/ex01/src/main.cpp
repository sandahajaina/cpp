/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 17:23:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

int main()
{
    {
        Form form("f_258", 50, 0); // grade required to execute it < 1

        Form form1("B13", 184, 0); // grade required to sign it > 150

        Form form2("appolo_21", 5, 180); // grade required to execute it > 150
    }

    {
        std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
        Form form("appolo_21", 5, 20);
        Bureaucrat saotra("Saotra", 30);
        std::cout << saotra << '\n';
        std::cout << form << '\n';
        saotra.signForm(form);

        std::cout << '\n';

        Bureaucrat sanda("Sanda", 1);
        std::cout << sanda << '\n';
        std::cout << form << '\n';
        sanda.signForm(form);
        std::cout << form << '\n';

        std::cout << '\n';

        Bureaucrat fana("fana", 2);
        fana.signForm(form);
        sanda.signForm(form);
    }
    
    return  0;
}