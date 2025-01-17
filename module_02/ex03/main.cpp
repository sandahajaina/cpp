/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/16 14:46:16 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void check_result(bool result, Point point)
{
    if (result)
        std::cout << point << " is strictly inside the triangle." << std::endl;
    else
        std::cout << point << " is outside the triangle or lies on its edges." << std::endl;
}

int main(void)
{
    Point a(-2, -3);
    Point b(0, 5);
    Point c(5, 0);

    Point point1(-1, -2);
    Point point2(-1, -3);
    Point point3(4, 1.01f);
    Point point4(2.99f, 2);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;

    bool result1, result2, result3, result4;

    result1 = bsp(a, b, c, point1);
    result2 = bsp(a, b, c, point2);
    result3 = bsp(a, b, c, point3);
    result4 = bsp(a, b, c, point4);

    check_result(result1, point1);
    check_result(result2, point2);
    check_result(result3, point3);
    check_result(result4, point4);

    return 0;
}