/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:51:05 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/20 16:42:21 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{

    FragTrap ft1("Saotra");
    FragTrap ft2;

    std::cout << "===Special capacity===" << std::endl;
    ft1.highFivesGuys();
    ft2 = ft1;
    std::cout << ft2 << std::endl;
    FragTrap ft3(ft2);
    ft3.attack("fana");
    std::cout << ft3 << std::endl;

    return 0;
}