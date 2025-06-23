/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 07:39:07 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/23 17:21:03 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        static void parseInput(int, char**, std::vector<unsigned int>&, std::deque<unsigned int>&);
    public:
        static void process(int , char**);
};
