/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:32:48 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/24 17:53:00 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
}

Character::Character(const std::string& name) : _name(name) {}

Character::Character( const Character & src )
{
	(void) src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void) rhs;
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Character const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	(void) i;
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	(void) m;
}

void Character::unequip(int idx)
{
	(void) idx;
}

void Character::use(int idx, ICharacter& target)
{
	(void) idx;
	(void) target;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Character::getName() const
{
	return _name;
}


/* ************************************************************************** */