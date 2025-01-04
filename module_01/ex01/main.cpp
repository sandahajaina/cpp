/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:03 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 16:48:46 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zombie_horde1 = zombieHorde(N, "Saotra");
    Zombie *zombie_horde2 = zombieHorde(N, "Fahasoavana");

    for (int i = 0; i < N; i++)
        zombie_horde1[i].announce();

    for (int i = 0; i < N; i++)
        zombie_horde2[i].announce();

    delete [] zombie_horde1;    
    delete [] zombie_horde2;    
    
    return (0);
}