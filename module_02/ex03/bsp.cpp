/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:57:39 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/16 14:30:50 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"


// Area = |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)| / 2
static Fixed triangleArea(Point const& p1, Point const& p2, Point const& p3) {
    Fixed result = 
        (p1.getX() * (p2.getY() - p3.getY())) +
        (p2.getX() * (p3.getY() - p1.getY())) +
        (p3.getX() * (p1.getY() - p2.getY()));

    return result < 0 ? -result / Fixed(2) : result / Fixed(2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed totalArea = triangleArea(a, b, c);

    Fixed area1 = triangleArea(point, b, c);
    Fixed area2 = triangleArea(a, point, c);
    Fixed area3 = triangleArea(a, b, point);

    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0)) {
        return false;
    }

    Fixed sumOfAreas = area1 + area2 + area3;
    return (sumOfAreas >= totalArea && sumOfAreas <= totalArea);
}
