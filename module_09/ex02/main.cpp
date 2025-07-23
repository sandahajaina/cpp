/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:29:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/23 16:52:41 by sranaivo         ###   ########.fr       */
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

std::vector<int> jacobsthalSequence(int n)
{
    std::vector<int> seq;
    int j0 = 0, j1 = 1;

    if (n == 0)
        return seq;

    while (true)
    {
        int jn = j1 + (2 * j0);
        if (jn >= n)
            break;
        seq.push_back(jn);
        j0 = j1;
        j1 = jn;
    }
    
    return seq;
}

void insertMin(std::vector<int>& max, std::vector<int>& min)
{
    std::vector<int> seq = jacobsthalSequence(static_cast<int>(min.size()));
    
    for (std::vector<int>::iterator it = seq.begin(); it != seq.end(); ++it)
    {
        int i = *it;
        if (i > static_cast<int>(min.size()))
            return ;
        int value = min[i];
        std::cout<< "i : " << i << '\n';
        std::vector<int>::iterator pos = std::lower_bound(max.begin(), max.end(), value);
        max.insert(pos, value);
    }
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

    // std::vector<int> result;
    
    // result.push_back(min[0]);

    // for (size_t i = 0; i < max.size(); i++)
    // {
    //     result.push_back(max[i]);
    // }

    // print_vector(result);

    insertMin(max, min);

    vec = max;

    std::cout << "max: ";
    print_vector(max);
    std::cout << "min: ";
    print_vector(min);
}

int main(int ac, char** av)
{
    std::vector<int> vec;
    std::deque<int> deq;

    parseInput(ac, av, vec, deq);
    merge_insert(vec);
    std::cout << "result: ";
    print_vector(vec);
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