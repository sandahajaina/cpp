/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:51:52 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/29 15:06:13 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main()
{
    BitcoinExchange bitcoin;
    bitcoin.readDataBase("data.csv");

    return 0;
}