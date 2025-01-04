/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:44:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 17:58:10 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout   << this->_name << " attacks with their "
                << this->_weapon.getType() << std::endl;  
}

HumanA::HumanA(std::string name, Weapon weapon) : _name(name)
{
    this->_weapon = weapon;
}

HumanA::~HumanA() {}