/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:04:18 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/10 07:54:56 by sranaivo         ###   ########.fr       */
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
    if (this != &other)
    {
        _container = other._container;
        N = other.N;
    }
    return *this;
}

Span::~Span() {}

const std::vector<int>& Span::getContainer() const
{
    return _container;
}

Span::Span(unsigned int n) : N(n) {}

void Span::addNumber(int n)
{
    if (_container.size() >= N)
        throw std::runtime_error("Span is full");
    _container.push_back(n);
}

int Span::shortestSpan() const
{
    if (_container.size() <= 1)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> tmp = _container;
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size() - 1; ++i)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_container.size() <= 1)
        throw std::runtime_error("Not enough numbers to find a span");
    
    int min = *(std::min_element(_container.begin(), _container.end()));
    int max = *(std::max_element(_container.begin(), _container.end()));

    return (max - min);
}

void Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _container.size() > N)
        throw std::runtime_error("Not enough numbers to find a span");
    _container.insert(_container.end(), begin, end);
}