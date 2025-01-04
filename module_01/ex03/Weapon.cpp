/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:20:06 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 18:16:05 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
    return this->_type;
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::Weapon() {}

Weapon::~Weapon() {}