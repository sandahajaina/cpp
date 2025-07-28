/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:25:18 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/28 15:28:51 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isValidNumber(const std::string& str)
{
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
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

std::deque<int> jacobsthalSequenceDeque(int n)
{
    std::deque<int> seq;
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

    std::deque<bool> seen(n, false);

    for(std::deque<int>::iterator it = seq.begin(); it != seq.end(); ++it)
        seen[*it] = true;

    for (int i = 0; i < n; i++)
    {
        if (!seen[i])
            seq.push_back(i);
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
        std::vector<int>::iterator pos = std::lower_bound(max.begin(), max.end(), value);
        max.insert(pos, value);
    }
}

void insertMin(std::deque<int>& max, std::deque<int>& min)
{
    std::deque<int> seq = jacobsthalSequenceDeque(static_cast<int>(min.size()));
    
    for (std::deque<int>::iterator it = seq.begin(); it != seq.end(); ++it)
    {
        int i = *it;
        if (i > static_cast<int>(min.size()))
            return ;
        int value = min[i];
        std::deque<int>::iterator pos = std::lower_bound(max.begin(), max.end(), value);
        max.insert(pos, value);
    }
}