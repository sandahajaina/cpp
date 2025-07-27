/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:39:07 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/27 21:34:17 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <exception>
#include <set>
#include <limits>
#include <cstdlib>
#include <string>
#include <sys/time.h>

std::vector<int> jacobsthalSequence(int n);
void parseInput(int ac, char** av, std::vector<int>& vec, std::deque<int>& deq);

template <typename Container>
void print_vector(Container vec)
{
    for (typename Container::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <class Container>
void insertMin(Container& max, Container& min)
{
    std::vector<int> seq = jacobsthalSequence(static_cast<int>(min.size()));
    
    for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); ++it)
    {
        int i = *it;
        if (i > static_cast<int>(min.size()))
            return ;
        int value = min[i];
        typename Container::iterator pos = std::lower_bound(max.begin(), max.end(), value);
        max.insert(pos, value);
    }
}

template <class Container>
void merge_insert(Container& vec)
{
    Container max;
    Container min;

    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        max.push_back( (vec[i] > vec[i + 1]) ? vec[i] : vec[i + 1] );
        min.push_back( (vec[i] < vec[i + 1]) ? vec[i] : vec[i + 1] );
    }
    
    if (vec.size() % 2 != 0)
        max.push_back(vec[vec.size() - 1]);

    if (max.size() > 1)
        merge_insert(max);

    insertMin(max, min);

    vec = max;
}