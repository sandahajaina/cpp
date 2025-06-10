/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:52:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/10 16:31:17 by sranaivo         ###   ########.fr       */
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

std::map<std::string, float> BitcoinExchange::getDatabase()
{
    return _database;
}

void BitcoinExchange::loadDataBase(const std::string& filename)
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

            if (!std::getline(ss, date, ',') || !std::getline(ss, value))
            {
                std::cout << "Warning: malformed line => " << line << '\n';
                continue;
            }

            std::stringstream valStream(value);
            float rate;
            valStream >> rate;

            if (valStream.fail())
            {
                std::cout << "Warning: invalid rate => " << value << std::endl;
                continue ;
            }

            _database[date] = rate;
        }
        file.close();
    } else {
        std::cout << "Error: could not open file: " << filename << '\n';
        return ;
    }
}

void BitcoinExchange::execute(const std::string& filename)
{
    std::ifstream input(filename.c_str());
    if (input.is_open())
    {
        std::string line;
        std::getline(input, line);
        if (line.compare("date | value") != 0)
        {
            std::cout << "Error: bad header\n";
            return; 
        }
        while (std::getline(input, line))
        {
            std::stringstream ss(line);
            std::string date, sep, value;

            if (!std::getline(ss, date, ',') || !std::getline(ss, value))
            {
                std::cout << "Error: bad input => " << line << '\n';
			    continue;
            }

            
        }
    }
    else
    {
        std::cout << "Error: could not open file: " << filename << '\n';
        return;
    }
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}