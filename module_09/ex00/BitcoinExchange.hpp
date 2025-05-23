/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:52:09 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/23 12:28:12 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange(/* args */);
        BitcoinExchange(const BitcoinExchange&);
        BitcoinExchange& operator=(const BitcoinExchange&);
        ~BitcoinExchange();

        void readDataBase(const std::string&);
        
    private:
        std::map<std::string, double> _dataBase;
};