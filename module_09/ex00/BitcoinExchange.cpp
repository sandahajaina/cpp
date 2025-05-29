/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:52:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/29 16:38:46 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <string>

BitcoinExchange::BitcoinExchange(/* args */) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&) {return *this;}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::readDataBase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    std::string line;
    if (file.is_open())
    {
        std::getline(file, line);
        while (std::getline(file, line))
        {
            std::stringstream ss(line);
            std::string date;
            std::string value;

            
        }
    }
}