/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/03 16:45:29 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

int main()
{
    {
        Intern saotra;

        AForm* form = saotra.makeForm("robotomy request", "Bender");
        std::cout << "form: " << form->getName() << ", target: " << form->getTarget() << '\n';

        std::cout << '\n';

        AForm* form1 = saotra.makeForm("presidential pardon", "John");
        std::cout << "form: " << form1->getName() << ", target: " << form1->getTarget() << '\n';

        std::cout << '\n';

        AForm* form2 = saotra.makeForm("shrubbery creation", "home");
        std::cout << "form: " << form2->getName() << ", target: " << form2->getTarget() << '\n';

        std::cout << '\n';

        AForm* form3 = saotra.makeForm("friend request", "Agata");
        if (form3 == NULL)
            std::cout << "NULL" << '\n';

        delete form;
        delete form1;
        delete form2;
    }
    return  0;
}