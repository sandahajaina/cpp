/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:10:07 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/29 11:47:24 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"),
	ScavTrap("Default_clap_name"), FragTrap("Default_clap_name"), _name("Default")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "hitPoint: " << _hitPoints <<std::endl;
    std::cout << "energyPoint: " << _energyPoints <<std::endl;
    std::cout << "attackDamage: " << _attackDamage <<std::endl;

	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), // Initialisation unique de ClapTrap
      ScavTrap(), FragTrap(),
      _name(name) 
{
    // FORCER L'INITIALISATION CORRECTE DES ATTRIBUTS :
    _hitPoints = FragTrap::_hitPoints;       // 100 (correct)
    _energyPoints = ScavTrap::_energyPoints; // 50 (correct)
    _attackDamage = FragTrap::_attackDamage; // 30 (correct)

	std::cout << "hitPoint: " << _hitPoints <<std::endl;
    std::cout << "energyPoint: " << _energyPoints <<std::endl;
    std::cout << "attackDamage: " << _attackDamage <<std::endl;

    std::cout << "DiamondTrap constructor called for: " << _name << std::endl;
}


// DiamondTrap::DiamondTrap(std::string name):  ClapTrap(name + "_clap_name"),
// 	ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name)
// {
// 	std::cout << "DiamondTrap parametric constructor called for " << this->_name << std::endl;
// }


DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	*this = src;
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called for " << this->_name << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
	}
	std::cout << "DiamondTrap copy assignement operator called for : " << this->_name << std::endl;
	return *this;
}


std::ostream &			operator<<( std::ostream & o, DiamondTrap const & i )
{
	o << "(" << "Name: " << i.get_name()
		<< ", " << "ClapTrap name: " << i.ClapTrap::get_name()
		<< ", " << "hit points: " << i.get_hitPoints()
		<< ", " << "energy points: " << i.get_energyPoints()
		<< ", " << "attack damage: " << i.get_attackDamage()
		<< ")";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << _name << " | " << "ClapTrap name: "
			<< ClapTrap::_name << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& DiamondTrap::get_name() const
{
	return this->_name;
}

/* ************************************************************************** */