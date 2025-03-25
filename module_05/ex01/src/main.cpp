/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/25 22:25:43 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main()
{
    {
        std::cout << "~~~~~~~~~~~~~~~~~~~~" << '\n';
        Form form("form_grave", 5, 20);
        Bureaucrat saotra("Saotra", 30);
        std::cout << saotra << '\n';
        std::cout << form << '\n';
        saotra.signForm(form);

        Bureaucrat sanda("Sanda", 1);
        std::cout << sanda << '\n';
        sanda.signForm(form);
        std::cout << form << '\n';
    }
    
    return  0;
}