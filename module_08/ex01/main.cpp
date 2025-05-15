/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:40:58 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/14 14:09:07 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    {
        std::cout << "~~~~~~~~~~~~~~~~~~~~\n";
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~\n";

    }

    {
        Span sp(10010);
        try
        {
            for (size_t i = 0; i < 10011; i++)
                sp.addNumber(rand());
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << "shortest span: " << sp.shortestSpan() << '\n';
        std::cout << "longest span: " << sp.longestSpan() << '\n';
    }

    {
        std::cout << "\n~~~~~~~~~~~~~~\n";
        Span sp(6);
        try
        {
            sp.addNumber(-5);
            sp.addNumber(0);
            sp.addNumber(15);
            sp.addNumber(150);
            sp.addNumber(42);
            sp.addNumber(-3);

            sp.addNumber(465);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "shortest span: " << sp.shortestSpan() << '\n';
        std::cout << "longest span: " << sp.longestSpan() << '\n';
    }

    {
        std::cout << "\n~~~fillSpan~~~" << '\n';
        std::vector<int> lst;
        lst.push_back(42);
        lst.push_back(2);
        lst.push_back(4);
        lst.push_back(8);
        lst.push_back(32);
        lst.push_back(-9);
        lst.push_back(120);

        Span sp(100);
        sp.fillSpan(lst.begin(), lst.end());

        for (size_t i = 0; i < sp.getContainer().size(); i++)
        {
            std::cout << sp.getContainer()[i] << '\n';
        }
    }

    {
        std::cout << "\n~~~~~~~~~~~~~\n";
        Span sp(30);
        sp.addNumber(-42);

        try
        {
            std::cout << sp.shortestSpan();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    return 0;
}