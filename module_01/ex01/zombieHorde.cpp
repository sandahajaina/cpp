/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:22:41 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 16:41:37 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie *zombie_horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombie_horde[i].set_name(name);
    }
    return zombie_horde;
}