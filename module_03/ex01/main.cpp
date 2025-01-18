/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:51:05 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/18 17:54:37 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("saotra");

    std::cout << a << std::endl;
    a.guardGate();
    a.attack("fana");
    a.guardGate();
    a.takeDamage(1000);
    a.beRepaired(200);
    std::cout << a << std::endl;
    
    return 0;
}