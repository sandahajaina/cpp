/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:32:48 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/27 17:07:20 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/AMateria.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

int Character::_inventoryNb = 4;

Character::Character() : _nbMateria(0)
{
	for (int i = 0; i < _inventoryNb; i++)
		_materias[i] = NULL;
}

Character::Character(const std::string& name) : _name(name), _nbMateria(0) 
{
	for (int i = 0; i < _inventoryNb; i++)
		_materias[i] = NULL;
}

Character::Character( const Character & src )
{
	_nbMateria = src._nbMateria;
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (src._materias[i] != NULL)
			_materias[i] = src._materias[i]->clone();
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (_materias[i] != NULL)
			delete _materias[i];
	}
	
	_nbMateria = rhs._nbMateria;
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (_materias[i] != NULL)
			_materias[i] = rhs._materias[i]->clone();
	}
	
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
	if (_nbMateria == _inventoryNb)
		return ;
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			break;
		}
	}
	_nbMateria++;
}

void Character::unequip(int idx)
{
	if (_materias[idx] != NULL)
	{
		// save the address
		_materias[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (_materias[idx] != NULL)
		_materias[idx]->use(target);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Character::getName() const
{
	return _name;
}


/* ************************************************************************** */