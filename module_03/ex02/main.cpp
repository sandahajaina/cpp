/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:51:05 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/18 18:06:20 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "=== Creating FragTrap ===" << std::endl;
    FragTrap ft1("Fraggy");

    std::cout << "\n=== Testing Special Function ===" << std::endl;
    ft1.highFivesGuys();

    std::cout << "\n=== Copying FragTrap ===" << std::endl;
    FragTrap ft2(ft1);

    std::cout << "\n=== Assigning FragTrap ===" << std::endl;
    FragTrap ft3;
    ft3 = ft1;

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}