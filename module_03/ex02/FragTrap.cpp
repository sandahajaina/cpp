/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:48:04 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/18 18:02:56 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap parameterized constructor called for " << name << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << "FragTrap copy constructor called for " << this->_name << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
	}
	std::cout << "FragTrap assignement operator called for : " << this->_name << std::endl;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << "(" << "Name: " << i.get_name()
		<< ", " << "hit points: " << i.get_hitPoints()
		<< ", " << "energy points: " << i.get_energyPoints()
		<< ", " << "attack damage: " << i.get_attackDamage()
		<< ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */