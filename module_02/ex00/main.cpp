/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/16 12:43:58 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
    {
        Fixed a;
        Fixed b( a );
        Fixed c;
        c = b;
        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }
    {
        std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
        Fixed x;
        x.setRawBits(12);
        std::cout << "x: " << x.getRawBits() << std::endl;
    }
    return 0;
}