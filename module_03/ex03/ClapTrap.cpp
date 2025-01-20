/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:26:47 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/20 16:22:38 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10),
					_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "Copy constructor called for " << this->_name << std::endl;
	*this = src;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
							_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor with name called for " << this->_name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << "Copy assignement operator called for : " << this->_name << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs.get_name();
		this->_hitPoints = rhs.get_hitPoints();
		this->_energyPoints = rhs.get_energyPoints();
		this->_attackDamage = rhs.get_attackDamage();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ClapTrap const & i )
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

void ClapTrap::attack(const std::string& target)
{
	std::cout << "[attack] ";
	if (checkHealth() == false)
		return;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			<< ", causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[takeDamage] ";
	if (checkHealth() == false)
		return;
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage"
			<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[beRepaired] ";
	if (checkHealth() == false)
		return;
	std::cout << "ClapTrap " << this->_name << " won " << amount << " hit points."
			<< std::endl;
	this->_hitPoints += amount;
	this->_energyPoints--;
}

bool ClapTrap::checkHealth() const
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have any hit points left."
				<< std::endl;
		return false;
	} else if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have any energy points left."
				<< std::endl;
		return false;
	}
	return true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& ClapTrap::get_name() const
{
	return this->_name;
}

unsigned int ClapTrap::get_hitPoints() const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::get_energyPoints() const
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::get_attackDamage() const
{
	return (this->_attackDamage);
}

/* ************************************************************************** */