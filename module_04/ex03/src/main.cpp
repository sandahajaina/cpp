/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:42:30 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/27 17:33:11 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"

// static void println(const std::string& str) 
// {
//     std::cout << str << std::endl;
// }

int main()
{
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = new Ice();
    me->equip(tmp);
    AMateria* cure = new Cure();
    me->equip(cure);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;

    return 0;
}