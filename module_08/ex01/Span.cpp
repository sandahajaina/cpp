/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:04:18 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/08 17:09:04 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& other) 
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    _container.clear();
    _container = other._container;
    N = other.N;
    return *this;
}

Span::~Span() {}

Span::Span(unsigned int n)
{
    N = n;
}

void Span::addNumber(long n)
{
    if (_container.size() >= N)
        throw std::out_of_range("Span full");
    _container.push_back(static_cast<int>(n));
}