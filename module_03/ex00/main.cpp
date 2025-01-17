/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:51:05 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/17 17:46:41 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap andria;
    ClapTrap saotra("Saotra");

    std::cout << saotra << std::endl;
    saotra.attack("fana");
    saotra.takeDamage(9);
    std::cout << saotra << std::endl;
    saotra.beRepaired(20);
    std::cout << saotra << std::endl;
    saotra.takeDamage(100);
    std::cout << saotra << std::endl;
    
    return 0;
}