/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:32 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/14 23:55:24 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//constructor & destructor
Fixed::Fixed() : _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src ) : _rawBits(src._rawBits)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
	// std::cout << "Int constructor called." << std::endl;
	this->_rawBits = x << this->fractionalBits;
	return;
}

Fixed::Fixed(const float x)
{
	// std::cout << "Float constructor called." << std::endl;
	this->_rawBits = roundf(x * (1 << this->fractionalBits));
	return;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	// std::cout << "Copy assignement operator called." << std::endl;
	if ( this != &rhs )
	{
		this->_rawBits = rhs.getRawBits();
	}
	return *this;
}

int	Fixed::toInt(void) const
{
	return roundf(this->_rawBits / (1 << this->fractionalBits));
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << this->fractionalBits));
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

std::ostream &			operator<<( std::ostream & os, Fixed const & i )
{
	os << i.toFloat();
	return os;
}

// 6 operateur de coparaison
bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->_rawBits > rhs._rawBits);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->_rawBits < rhs._rawBits);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_rawBits >= rhs._rawBits);
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_rawBits <= rhs._rawBits);
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->_rawBits == rhs._rawBits);
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_rawBits != rhs._rawBits);
}

// Arithmetic

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + rhs._rawBits);
	return result;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - rhs._rawBits);
	return result;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	Fixed result;
	result.setRawBits((this->_rawBits * rhs._rawBits) / (1 << fractionalBits));
	return result;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed result;
	result.setRawBits((this->_rawBits * (1 << fractionalBits)) / rhs._rawBits);
	return result;
}

// Increment | decrement

Fixed Fixed::operator++()
{
	_rawBits += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_rawBits += 1;
	return (temp);
}

Fixed Fixed::operator--()
{
	_rawBits -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_rawBits -= 1;
	return (temp);
}

// min && max

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

/* ************************************************************************** */