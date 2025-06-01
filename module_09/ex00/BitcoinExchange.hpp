/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:52:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/01 11:24:40 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
    public:
        BitcoinExchange(/* args */);
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        ~BitcoinExchange();

        std::map<std::string, float> getDatabase();
        void loadDataBase(const std::string&);
        void execute(const std::string&);
        
    private:
        std::map<std::string, float> _database;
        bool isValideDate(const std::string&);
};