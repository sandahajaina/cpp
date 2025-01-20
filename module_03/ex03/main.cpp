/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:51:05 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/20 16:43:50 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "===Constructor===" << std::endl;

    DiamondTrap dt("saotra");

    std::cout << "=================" << std::endl;

    std::cout << dt << std::endl;
    dt.attack("fana");

    std::cout << "===Special capacity===" << std::endl;

    dt.whoAmI();

    dt.takeDamage(1000);

    dt.attack("fana");

    std::cout << "===Destructor===" << std::endl;
    return 0;
}