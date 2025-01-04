/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:03 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 16:16:14 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int main()
{
    Zombie *zombie1 = newZombie("Saotra");
    Zombie *zombie2 = newZombie("Andria");
    zombie1->announce();
    zombie2->announce();

    randomChump("Nomena");
    randomChump("Fahasoavana");
    delete zombie1;
    delete zombie2;

    return (0);
}