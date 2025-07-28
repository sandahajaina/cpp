/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:39:07 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/28 15:32:47 by sranaivo         ###   ########.fr       */
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
std::deque<int> jacobsthalSequenceDeque(int n);
bool isValidNumber(const std::string& str);
void insertMin(std::vector<int>& max, std::vector<int>& min);
void insertMin(std::deque<int>& max, std::deque<int>& min);

template <typename Container>
void parseInput(int ac, char** av, Container& vec)
{
    std::set<unsigned int> seen;

    for (int i = 1; i < ac; ++i)
    {
        std::string token(av[i]);

        if (!isValidNumber(token)) {
            throw std::invalid_argument("Invalid input: " + token);
        }

        long value = std::strtol(token.c_str(), NULL, 10);
        if (value < 0 || value > std::numeric_limits<int>::max()) {
            throw std::out_of_range("Too large a number: " + token);
        }

        if (!seen.insert(static_cast<unsigned int>(value)).second) {
            throw std::runtime_error("Duplicate number: " + token);
        }

        vec.push_back(static_cast<int>(value));
    }

    if (vec.empty()){
        throw std::runtime_error("Error: no valid input provided.");
    }
}

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