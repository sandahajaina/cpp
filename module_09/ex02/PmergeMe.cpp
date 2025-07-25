/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:25:18 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/25 16:02:31 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void parseInput(int ac, char** av, std::vector<int>& vec, std::deque<int>& deq)
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

    std::vector<bool> seen(n, false);

    for(std::vector<int>::iterator it = seq.begin(); it != seq.end(); ++it)
        seen[*it] = true;

    for (int i = 0; i < n; i++)
    {
        if (!seen[i])
            seq.push_back(i);
    }
    
    return seq;
}