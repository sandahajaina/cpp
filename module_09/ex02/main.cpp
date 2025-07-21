/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:29:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/21 16:42:11 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>
#include <set>
#include <limits>
#include <cstdlib>
#include <string>

static bool isValidNumber(const std::string& str)
{
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

static void parseInput(int ac, char** av, std::vector<int>& vec, std::deque<int>& deq)
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
        deq.push_back(static_cast<int>(value));
    }

    if (vec.empty()){
        throw std::runtime_error("Error: no valid input provided.");
    }
}

void print_vector(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void merge_insert(std::vector<int>& vec)
{
    std::vector<int> max;
    std::vector<int> min;

    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        max.push_back( (vec[i] > vec[i + 1]) ? vec[i] : vec[i + 1] );
        min.push_back( (vec[i] < vec[i + 1]) ? vec[i] : vec[i + 1] );
    }
    
    if (vec.size() % 2 != 0)
        max.push_back(vec[vec.size() - 1]);

    if (max.size() > 1)
        merge_insert(max);

    print_vector(max);
    std::cout << "-- ";
    print_vector(min);
    std::cout << "-- \n";

    
    // jachosbsatal
}

int main(int ac, char** av)
{
    std::vector<int> vec;
    std::deque<int> deq;

    parseInput(ac, av, vec, deq);
    merge_insert(vec);

    // try {
    //     std::cout << "Parsed input: ";
    //     for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    //         std::cout << *it << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // catch (std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     return 1;
    // }
}