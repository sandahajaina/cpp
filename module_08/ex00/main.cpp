/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:52:54 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/07 15:57:27 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    std::list<int> lst;

    for (size_t i = 0; i < 50; i++)
    {
        int x = rand() % 50;
        lst.push_back(x);
    }

    int to_find = rand() % 50;

    try
    {
        std::list<int>::iterator it = easyfind(lst, to_find);
        std::cout << "Value found: " << *it << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
    
    return 0;
}