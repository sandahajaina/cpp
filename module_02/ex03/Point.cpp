/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:31:36 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/15 10:56:34 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// constructor & destructor
Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point &src): _x(src._x), _y(src._y) {}

Point::~Point() {}

const Fixed Point::getX() const
{
    return this->_x;
}

const Fixed Point::getY() const
{
    return this->_y;
}

Point Point::operator=(const Point& p)
{
    (void) p;
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
    os << "Point(" << p.getX().toFloat() << ", " << p.getY().toFloat() << ")";
    return os;
}