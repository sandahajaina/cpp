/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:45:31 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/29 16:05:41 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

int main()
{
    std::srand(std::time(0));
    
    {
        for (int i = 0; i < 5; i++)
        {
            Base* b = generate();
            identify(b);
            free(b);
            b = NULL;
        }
    }

    {
        for (int i = 0; i < 5; i++)
        {
            Base* b = generate();
            Base& r = *b;
            identify(r);
            free(b);
            b = NULL;
        }
    }
    
    return 0;    
}