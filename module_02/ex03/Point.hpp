/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:08:40 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/15 00:31:32 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point();
        Point(float const x, float const y);
        Point(Point const & src);
        ~Point();
        const Fixed getX() const;
        const Fixed getY() const;

        Point operator=(Point const & p);
};

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif