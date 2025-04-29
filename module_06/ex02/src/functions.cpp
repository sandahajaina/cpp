/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:11:11 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/29 16:08:02 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base * generate(void)
{   
    int random = std::rand() % 3;
    
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A\n";
        (void) a;
        return ;
    }
    catch(const std::exception&) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B\n";
        (void) b;
        return ;
    }
    catch(const std::exception&) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "A\n";
        (void) c;
        return ;
    }
    catch(const std::exception&) {}

    std::cout << "Unknown type\n";
}