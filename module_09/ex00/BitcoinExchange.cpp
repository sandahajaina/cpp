/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:52:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/07/29 16:56:55 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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

            if (!std::getline(ss, date, '|') || !std::getline(ss, value))
            {
                std::cout << "Error: bad input => " << line << '\n';
			    continue;
            }

            date = trim(date);
            value = trim(value);

            std::stringstream valStream(value);
            float btc;
            valStream >> btc;

            if (valStream.fail())
            {
                std::cout << "Error: invalid value => " << value << '\n';
                continue;
            }

            if (btc == -0)
                btc = 0;

            if (btc < 0)
            {
                std::cout << "Error: not a positive number.\n";
                continue;
            }
            if (btc > 1000)
            {
                std::cout << "Error: too large a number.\n";
                continue; 
            }

            if (!isValidDate(date))
            {
                std::cout << "Error: invalid date => " << date << '\n';
                continue;
            }

            std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

            if (it == _database.end() || it->first != date)
            {
                if (it == _database.begin())
                {
                    std::cout << "Error: no earlier date found for " << date << '\n';
                    continue;
                }
                --it;
            }

            float rate = it->second;
            float result = rate * btc;

            std::cout << date << " => " << btc << " = " << result << '\n';
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

bool BitcoinExchange::isValidDate(const std::string& dateStr)
{
    if (dateStr.length() != 10 ||
        !isdigit(dateStr[0]) || !isdigit(dateStr[1]) || !isdigit(dateStr[2]) || !isdigit(dateStr[3]) ||
        dateStr[4] != '-' ||
        !isdigit(dateStr[5]) || !isdigit(dateStr[6]) ||
        dateStr[7] != '-' ||
        !isdigit(dateStr[8]) || !isdigit(dateStr[9])) {
            return false;
    }

    int year = std::atoi(dateStr.substr(0, 4).c_str());
    int month = std::atoi(dateStr.substr(5, 2).c_str());
    int day = std::atoi(dateStr.substr(8, 2).c_str());

    std::tm tm = {};

    tm.tm_year = year - 1900;
    tm.tm_mon  = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;

    std::tm tm_copy = tm;
    std::mktime(&tm_copy);

    bool validDate (tm.tm_year == tm_copy.tm_year &&
            tm.tm_mon  == tm_copy.tm_mon &&
            tm.tm_mday == tm_copy.tm_mday);

    if (!validDate)
        return false;

    std::time_t inputTime = std::mktime(&tm);

    std::time_t now = std::time(0);
    std::tm* currentTm = std::localtime(&now);
    currentTm->tm_hour = 0;
    currentTm->tm_min = 0;
    currentTm->tm_sec = 0;

    std::time_t currentTime = std::mktime(currentTm);

    if (difftime(inputTime, currentTime) > 0)
        return false;

    return true;
}