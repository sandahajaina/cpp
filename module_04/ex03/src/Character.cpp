/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:32:48 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/28 16:06:51 by sranaivo         ###   ########.fr       */
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

Character::Character() : _nbMateria(0), _unequippedMateria(NULL)
{
	for (int i = 0; i < _inventoryNb; i++)
		_materias[i] = NULL;
}

Character::Character(const std::string& name) : _name(name), _nbMateria(0) 
{
	_unequippedMateria = NULL;
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
	if (_unequippedMateria != NULL)
		delete _unequippedMateria;
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
		if (rhs._materias[i] != NULL)
			_materias[i] = rhs._materias[i]->clone();
	}

	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m)
{
	if (_nbMateria == _inventoryNb)
		return ;
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (_materias[i] == m)
			return;
	}
	
	for (int i = 0; i < _inventoryNb; i++)
	{
		if (_materias[i] == NULL)
		{
			_materias[i] = m;
			_nbMateria++;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	if (_materias[idx] != NULL)
	{
		_saveUnequippedMateria(_materias[idx]);
		_materias[idx] = NULL;
		_nbMateria--;
		std::cout << "Materia at idx [" << idx << "] unequipped for " << _name << std::endl; 
	}
}

void Character::_saveUnequippedMateria(AMateria* m)
{
	if (_unequippedMateria != NULL)
	{
		delete _unequippedMateria;
		_unequippedMateria = m;
	}
	else
		_unequippedMateria = m;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return ;
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