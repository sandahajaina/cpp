/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/25 12:26:35 by sranaivo         ###   ########.fr       */
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
        try
        {
            Bureaucrat me("sanda", 5);
            std::cout << me << std::endl;
            Bureaucrat saotra("saotra", 200);
            std::cout << saotra << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        // incrementGrade()
        try
        {
            Bureaucrat her("her", 1);
            std::cout << her << std::endl;
            her.incrementGrade(); // trying to incement grade 1
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        // decrementGrade()
        Bureaucrat x("x_name", 149);
        x.decrementGrade();
        std::cout << x << std::endl;
        try
        {
            x.decrementGrade(); // trying to decrement grade 150
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    
    return  0;
}