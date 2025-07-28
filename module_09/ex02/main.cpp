/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:29:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/28 15:39:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    std::vector<int> vec;
    std::deque<int> deq;
    std::vector<int> cpy;

    timeval vStart, vEnd;
    timeval dStart, dEnd;

    try
    {
        parseInput(ac, av, cpy);

        gettimeofday(&vStart, NULL);
        parseInput(ac, av, vec);
        merge_insert(vec);
        gettimeofday(&vEnd, NULL);

        gettimeofday(&dStart, NULL);
        parseInput(ac, av, deq);
        merge_insert(deq);
        gettimeofday(&dEnd, NULL);

        std::cout << "Before: ";
        print_vector(cpy);

        std::cout << "After: ";
        print_vector(vec);

        double vElapsed = (vEnd.tv_sec - vStart.tv_sec) * 1000.0;
        vElapsed += (vEnd.tv_usec - vStart.tv_usec) / 1000.0;

        double dElapsed = (dEnd.tv_sec - dStart.tv_sec) * 1000.0;
        dElapsed += (dEnd.tv_usec - dStart.tv_usec) / 1000.0;

        std::cout << "Time to process a range of " << vec.size()
            << " elements with std::vector : " << vElapsed << " ms\n";

        std::cout << "Time to process a range of " << deq.size()
        << " elements with std::deque : " << dElapsed << " ms\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}