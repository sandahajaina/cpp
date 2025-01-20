/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:58:32 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/20 12:30:33 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed( const Fixed & src ) : _rawBits(src._rawBits) {}

Fixed::Fixed(const int x)
{
	this->_rawBits = x << this->_fractionalBits;
	return;
}

Fixed::Fixed(const float x)
{
	this->_rawBits = roundf(x * (1 << this->_fractionalBits));
	return;
}

Fixed::~Fixed() {}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
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
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
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
	result.setRawBits((this->_rawBits * rhs._rawBits) / (1 << _fractionalBits));
	return result;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	Fixed result;
	result.setRawBits((this->_rawBits * (1 << _fractionalBits)) / rhs._rawBits);
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