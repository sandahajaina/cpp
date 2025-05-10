/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:03:42 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/10 11:29:10 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
    public:
        Span();
        Span(const Span&);
        Span& operator=(const Span&);
        ~Span();

        Span(unsigned int N);
        void addNumber(int);
        int shortestSpan() const;
        int longestSpan() const;
        void fillSpan(std::vector<int>::iterator, std::vector<int>::iterator);
        const std::vector<int>&   getContainer() const;

    private:
        unsigned int        N;
        std::vector<int>    _container;
};

#endif