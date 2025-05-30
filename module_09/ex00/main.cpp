/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:51:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/30 15:12:33 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange bitcoin;
    bitcoin.readDataBase("data.csv");

    std::map<std::string, float> tmp = bitcoin.getDatabase();

    std::cout << tmp["2018-06-24"] << '\n';

    return 0;
}