/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:53:12 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/18 17:33:05 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string& name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor with name called for " << name << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src )
{
	*this = src;
	std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << "ScavTrap copy assignement operator called for : " << this->_name << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.get_name();
		this->_hitPoints = rhs.get_hitPoints();
		this->_energyPoints = rhs.get_energyPoints();
		this->_attackDamage = rhs.get_attackDamage();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ScavTrap const & i )
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

void ScavTrap::attack(const std::string& target)
{
	std::cout << "[attack] ";
	if (checkHealth() == false)
		return;
	std::cout << "ScavTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
	this->_energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */