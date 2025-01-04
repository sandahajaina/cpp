/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:18:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/04 17:57:30 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string type);
    Weapon();
    ~Weapon();
    const std::string&  getType() const;
    void                setType(std::string type);
};

#endif