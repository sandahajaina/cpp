/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:03:42 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/08 17:07:24 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class Span
{
    public:
        Span();
        Span(const Span&);
        Span& operator=(const Span&);
        ~Span();

        Span(unsigned int N);
        void addNumber(long);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

    private:
        unsigned int        N;
        std::vector<int>    _container;
};

#endif