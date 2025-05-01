/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:45:31 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/30 17:05:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
    std::srand(std::time(0));
    
    {
        std::cout << "void identify(Base* p)\n";
        for (int i = 0; i < 5; i++)
        {
            Base* b = generate();
            identify(b);
            delete b;
            b = NULL;
        }
    }

    {
        std::cout << "void identify(Base& p)\n";
        for (int i = 0; i < 5; i++)
        {
            Base* b = generate();
            Base& r = *b;
            identify(r);
            delete b;
            b = NULL;
        }
    }

    Base* b = NULL;
    identify(b);
    
    return 0;    
}