/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:32 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/16 13:01:20 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// default contructor
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// copy constructor
Fixed::Fixed( const Fixed & src ) : _rawBits(src._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

// constructor with const int
Fixed::Fixed(const int x)
{
	std::cout << "Int constructor called." << std::endl;
	this->_rawBits = x << this->_fractionalBits;
	return;
}

// constructor with const float
Fixed::Fixed(const float x)
{
	std::cout << "Float constructor called." << std::endl;
	this->_rawBits = roundf(x * (1 << this->_fractionalBits));
	return;
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignement operator called." << std::endl;
	if ( this != &rhs )
	{
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

int	Fixed::toInt(void) const
{
	return roundf(this->_rawBits / (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << this->_fractionalBits));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

// << overloading
std::ostream& operator<<( std::ostream & os, Fixed const & i )
{
	os << i.toFloat();
	return os;
}

/* ************************************************************************** */