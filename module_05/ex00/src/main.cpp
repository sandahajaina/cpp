/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 15:57:47 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main()
{
    {
        std::cout << "~~ Canonical form's test ~~" << '\n';
        Bureaucrat none;                // default constructor
        
        Bureaucrat me("sanda", 1);
        std::cout << me << std::endl;
        Bureaucrat her(me);             // copy constructor
        std::cout << her << std::endl;
        Bureaucrat saotra("saotra", 10);
        Bureaucrat fana("fana", 150);
        saotra = fana;                  // = operator
        std::cout << saotra << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
    }
    
    {
        std::cout << "~~ Exceptions' test ~~" << '\n';
        
        Bureaucrat me("sanda", 5);
        std::cout << me << std::endl;
        Bureaucrat saotra("saotra", 200);
        std::cout << saotra << std::endl;

        std::cout << '\n';
        
        // incrementGrade()
        Bureaucrat her("her", 1);
        std::cout << her << std::endl;
        her.incrementGrade(); // trying to incement grade 1

        // decrementGrade()
        Bureaucrat x("xxx", 149);
        x.decrementGrade();
        std::cout << x << std::endl;

        x.decrementGrade(); // trying to decrement grade 150
    }
    
    return  0;
}