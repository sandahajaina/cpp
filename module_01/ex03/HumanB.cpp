/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:50:25 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 18:12:21 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
    std::cout   << this->_name << " attacks with their "
                << this->_weapon.getType() << std::endl;  
}

void HumanB::setWeapon(Weapon weapon)
{
    this->_weapon = weapon;
}

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::~HumanB() {}