/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:51:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/01 11:30:10 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        BitcoinExchange bitcoin;
        bitcoin.loadDataBase("data.csv");

        std::map<std::string, float> tmp = bitcoin.getDatabase();

        bitcoin.execute(av[1]);
    }
    else
    {
        std::cout << "Error: could not open file\n";
    }
    return 0;
}