/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/01 14:41:22 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main()
{
    {
        Bureaucrat saotra("saotra", 150);
        ShrubberyCreationForm shrubbery_form("home");
        saotra.executeForm(shrubbery_form);
        Bureaucrat fana("fana", 15);
        fana.signForm(shrubbery_form);
        saotra.executeForm(shrubbery_form);
        fana.executeForm(shrubbery_form);
    }

    {
        std::cout << '\n';
        Bureaucrat saotra("saotra", 72);
        RobotomyRequestForm form("get_next");
        saotra.executeForm(form);
        saotra.signForm(form);
        Bureaucrat me("me", 1);
        saotra.executeForm(form);
        me.executeForm(form);
    }

    {
        std::cout << '\n';
        Bureaucrat saotra("saotra", 25);
        PresidentialPardonForm form("sranaivo");
        saotra.executeForm(form);
        saotra.signForm(form);
        Bureaucrat me("sanda", 1);
        saotra.executeForm(form);
        me.executeForm(form);
    }
    
    return  0;
}