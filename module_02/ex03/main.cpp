/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/15 17:28:54 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(5, 0);
    Point c(0, 5);
    Point point(1, 1);

    if (bsp(a, b, c, point) == true)
        std::cout << "in" << std::endl;
    else
        std::cout << "out" << std::endl;
    
    return 0;
}