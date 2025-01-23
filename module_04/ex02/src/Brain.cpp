/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:15:00 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/23 14:52:05 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain() : _index(0)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( const Brain & src ) : _index(0)
{
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		_index = rhs._index;
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Brain::setIdeas(const std::string& idea)
{
	if (_index < 100)
		this->_ideas[_index++] = idea;
	else
	{
		_index = 0;
		_ideas[_index++] = idea;
	}
}

void Brain::showIdeas() const
{
	for (int i = 0; i < _index; i++)
	{
		std::cout << _ideas[i];
		if (i + 1 < _index)
			std::cout << " | ";
		else
			std::cout << std::endl;
	}
	
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string* Brain::getIdeas()
{
	std::string* temp;
	temp = _ideas;
	return temp;
}


/* ************************************************************************** */