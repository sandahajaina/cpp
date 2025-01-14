/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/14 17:39:30 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
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
    return 0;
}