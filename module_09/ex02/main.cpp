/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:29:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/25 15:52:23 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    std::vector<int> vec;
    std::deque<int> deq;

    try
    {
        parseInput(ac, av, vec, deq);
        merge_insert(deq);
        merge_insert(vec);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    
    std::cout << "deq: ";
    print_vector(deq);

    std::cout << "vec: ";
    print_vector(deq);
    return 0;
}