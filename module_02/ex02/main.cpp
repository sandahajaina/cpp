/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/16 15:05:47 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    {
        Fixed           a;
        Fixed const     b(Fixed(5.05f) * Fixed(2));
        
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;

        std::cout << b << std::endl;
        
        std::cout << Fixed::max(a, b) << std::endl;
        {
            std::cout << "-----------------" << std::endl;
            Fixed           a;
            Fixed const     b(Fixed(5.05f) * Fixed(2));
            
            std::cout << "a: " << a << std::endl;
            std::cout << "++a: " << ++a << std::endl;
            std::cout << "a: " << a << std::endl;
            std::cout << "a++: " << a++ << std::endl;
            std::cout << "a: " << a << std::endl;

            std::cout << "b: " << b << std::endl;
            
            std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
        }
    }
    {
        std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
        Fixed a(0.99f);
        Fixed b(1);
        Fixed c(0.99f);

        if (a < b)
            std::cout << "a is less than b" << std::endl;
        if (a == c)
            std::cout << "a and c are equal" << std::endl;
        if (a != b)
            std::cout << "a is different from b" << std::endl;
    }
    {
        std::cout << "~~~~~~~~~~~~~~~~~~" << std::endl;
        Fixed a(0.5f);
        Fixed b(0.5f);
        Fixed c = a + b; // 1
        Fixed d(5);
        Fixed e(2);

        std::cout << "a + b: " << (a + b) << std::endl; // 1
        std::cout << "c - a: " << (c - a) << std::endl; // 0.5
        std::cout << "d / e: " << (d / e) << std::endl; // 2.5
        std::cout << "d * e: " << (d * e) << std::endl; // 10
    }
    return 0;
}