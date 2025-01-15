/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:39 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/15 17:30:18 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// static Fixed triangleArea(Point const& p1, Point const& p2, Point const& p3)
// {
//     return Fixed(
//         ((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())) +
//          (p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())) +
//          (p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))) /
//         2.0f
//     ).toFloat();
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
//     Fixed totalArea = triangleArea(a, b, c);

//     Fixed area1 = triangleArea(point, b, c);
//     Fixed area2 = triangleArea(a, point, c);
//     Fixed area3 = triangleArea(a, b, point);

    // std::cout << "1 :" << area1 << std::endl;
    // std::cout << "2 :" << area2 << std::endl;
    // std::cout << "3 :" << area3 << std::endl;
//     if (area1 == 0 || area2 == 0 || area3 == 0) {
//         return false;
//     }

//     return (true);
// }

static Fixed	sign(Point a, Point b, Point c)
{
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	d1, d2, d3;
	bool	has_neg, has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
