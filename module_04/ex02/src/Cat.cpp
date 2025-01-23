/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:50:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/23 15:08:36 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat( const Cat & src )
{
	AAnimal::operator=(src);
	_brain = new Brain(*(src._brain));
	std::cout << "Cat copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		delete _brain;
		AAnimal::operator=(rhs);
		_brain = new Brain(*(rhs._brain));
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Cat const & i )
{
	o << "Type = " << i.getType();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	std::cout << "**meowwww**" << std::endl;
}

void Cat::setIdea(const std::string& idea)
{
	_brain->setIdeas(idea);
}

void Cat::showIdeas() const
{
	std::cout << "Cat ideas : ";
	_brain->showIdeas();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */