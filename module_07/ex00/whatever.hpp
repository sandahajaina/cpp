/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:26:49 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/01 17:06:52 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap (T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class C>
C& min (C& a, C& b)
{
    return ((a < b) ? a : b);
}

template <class C>
C& max (C& a, C& b)
{
    return ((a > b) ? a : b);
}

#endif