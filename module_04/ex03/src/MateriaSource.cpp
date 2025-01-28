/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 08:59:54 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/28 15:38:08 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include "../inc/AMateria.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

int MateriaSource::_maxNbMateria = 4;

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < _maxNbMateria; i++)
		_learnedMaterias[i] = NULL;	
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	for (int i = 0; i < _maxNbMateria; i++)
	{
		if (src._learnedMaterias[i] != NULL)
			_learnedMaterias[i] = src._learnedMaterias[i]->clone();
		else
			_learnedMaterias[i] = NULL;
	}	
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _maxNbMateria; i++)
	{
		if (_learnedMaterias[i] != NULL)
			delete _learnedMaterias[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	for (int i = 0; i < _maxNbMateria; i++)
	{
		if (_learnedMaterias[i] != NULL)
			delete _learnedMaterias[i];
	}
	
	for (int i = 0; i < _maxNbMateria; i++)
	{
		if (rhs._learnedMaterias[i] != NULL)
			_learnedMaterias[i] = rhs._learnedMaterias[i]->clone();
		else
			_learnedMaterias[i] = NULL;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while (i < _maxNbMateria)
	{
		if (_learnedMaterias[i] == NULL)
		{
			_learnedMaterias[i] = m;
			break;
		}
		i++;
	}
	if (i == _maxNbMateria)
		delete m;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < _maxNbMateria; i++)
	{
		if (_learnedMaterias[i]->getType() == type)
			return (_learnedMaterias[i]->clone());
	}
	return 0;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */